package main

import (
	"fmt"
	"os"
	"sort"
	"strings"
)

func main() {
	const patternBase = "keyence"
	top := make([]byte, len(patternBase))
	bottom := make([]byte, len(patternBase))
	S := make([]byte, 101)

	fmt.Fscanf(os.Stdin, "%s", &S)

	len := len(S)
	found := false

	for offset := 0; offset < len(patternBase); offset++ {
		copy(top, patternBase[:offset])
		top[offset] = 0
		copy(bottom, patternBase[offset:])
		bottom[len(patternBase)-offset] = 0

		topSearch := strings.Index(string(S), string(top))
		if topSearch!= -1 {
			bottomSearch := strings.LastIndex(string(S[topSearch:]), string(bottom))
			if bottomSearch!= -1 {
				sepCount := 0

				if topSearch!= 0 {
					sepCount++
				}
				if topSearch+offset!= bottomSearch {
					sepCount++
				}
				if bottomSearch+len(bottom)!= len(S) {
					sepCount++
				}

				if sepCount <= 1 {
					found = true
					break
				}
			}
		}
	}

	fmt.Println((found? "YES" : "NO"))
}

