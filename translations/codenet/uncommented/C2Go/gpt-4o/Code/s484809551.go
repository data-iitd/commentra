package main

import (
	"fmt"
	"strings"
)

const (
	N_MAX = 100
	P_MAX = 100
)

func strrstr(s, substr string) string {
	lastIndex := -1
	for i := 0; i < len(s); i++ {
		if strings.HasPrefix(s[i:], substr) {
			lastIndex = i
		}
	}
	if lastIndex == -1 {
		return ""
	}
	return s[lastIndex:]
}

func main() {
	patternBase := "keyence"
	var S string

	fmt.Scan(&S)

	found := false

	for offset := 0; offset <= len(patternBase); offset++ {
		top := patternBase[:offset]
		bottom := patternBase[offset:]

		topSearch := strings.Index(S, top)
		if topSearch != -1 {
			bottomSearch := strrstr(S[topSearch+offset:], bottom)
			if bottomSearch != "" {
				sepCount := 0

				if topSearch != 0 {
					sepCount++
				}
				if topSearch+offset < len(S) && bottomSearch != S[topSearch+offset:] {
					sepCount++
				}
				if len(bottomSearch) > 0 && bottomSearch[len(bottomSearch)-1] != 0 {
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

// <END-OF-CODE>
