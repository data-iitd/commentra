package main

import (
	"fmt"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n)
	s := make([]string, n)

	for i := 0; i < n; i++ {
		var k string
		fmt.Scan(&k)
		s[i] = k
	}

	flag := 0
	d1 := []rune{}
	d2 := []rune{}
	rem := make(map[rune]struct{})

	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if i == j {
				d1 = append(d1, rune(s[i][j]))
			}
			if i == n-j-1 {
				d2 = append(d2, rune(s[i][j]))
			}
			if i != j && i != n-j-1 {
				rem[rune(s[i][j])] = struct{}{}
			}
		}
	}

	if len(rem) != 1 {
		fmt.Println("NO")
	} else if string(d1) != string(d2) {
		fmt.Println("NO")
	} else if len(d1) != len(uniqueRunes(d1)) {
		fmt.Println("NO")
	} else if len(rem) == 1 && contains(rem, d1[0]) {
		fmt.Println("NO")
	} else {
		fmt.Println("YES")
	}
}

func uniqueRunes(runes []rune) []rune {
	unique := make(map[rune]struct{})
	for _, r := range runes {
		unique[r] = struct{}{}
	}
	var result []rune
	for r := range unique {
		result = append(result, r)
	}
	return result
}

func contains(m map[rune]struct{}, r rune) bool {
	_, exists := m[r]
	return exists
}
