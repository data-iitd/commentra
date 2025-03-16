package main

import (
	"fmt"
	"strings"
)

func main() {
	patternBase := "keyence"
	var top, bottom [8]byte
	var S [101]byte

	fmt.Scanln(&S)

	len := len(S)
	found := false

	for offset := 0; offset < len(patternBase); offset++ {
		copy(top[:], patternBase[:offset])
		copy(bottom[:], patternBase[offset:])

		topSearch := strings.Index(string(S), string(top[:]))
		if topSearch != -1 {
			bottomSearch := strings.LastIndex(string(S[topSearch+offset:]), string(bottom[:]))
			if bottomSearch != -1 {
				sepCount := 0

				if topSearch != 0 {
					sepCount++
				}
				if topSearch+offset != bottomSearch {
					sepCount++
				}
				if bottomSearch+len(bottom) != len {
					sepCount++
				}

				if sepCount <= 1 {
					found = true
					break
				}
			}
		}
	}

	if found {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

