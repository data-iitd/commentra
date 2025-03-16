
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

const (
	N_MAX = 100
	P_MAX = 100
	DP_ARRAY_SIZE = N_MAX * P_MAX / 32 + 1
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	patternBase := "keyence"
	top := make([]byte, 8)
	bottom := make([]byte, 8)
	S := make([]byte, 101)
	fmt.Fscanln(reader, S)
	found := false
	for offset := 0; offset < len(patternBase); offset++ {
		copy(top, patternBase[:offset])
		copy(bottom, patternBase[offset:])
		topSearch := strings.Index(string(S), string(top))
		if topSearch!= -1 {
			bottomSearch := strings.LastIndex(string(S[topSearch+offset:]), string(bottom))
			if bottomSearch!= -1 {
				sepCount := 0
				if topSearch!= 0 {
					sepCount++
				}
				if topSearch+offset!= len(S)-len(bottom) {
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
	fmt.Println(func() string {
		if found {
			return "YES"
		}
		return "NO"
	}())
}

