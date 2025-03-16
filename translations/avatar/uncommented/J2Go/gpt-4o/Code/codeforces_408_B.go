package main

import (
	"fmt"
)

func main() {
	var s1, s2 string
	fmt.Scan(&s1, &s2)

	if !isValid(s1, s2) {
		fmt.Println(-1)
		return
	}

	m1 := make(map[rune]int)
	m2 := make(map[rune]int)

	for _, c := range s1 {
		m1[c]++
	}

	for _, c := range s2 {
		m2[c]++
	}

	ans := 0
	hs := make(map[rune]bool)

	for _, c := range s2 {
		if !hs[c] {
			hs[c] = true
			x1 := m1[c]
			x2 := m2[c]
			if x1 < x2 {
				ans += x1
			} else {
				ans += x2
			}
		}
	}

	fmt.Println(ans)
}

func isValid(s1, s2 string) bool {
	mapChars := make(map[rune]bool)

	for _, c := range s1 {
		mapChars[c] = true
	}

	for _, c := range s2 {
		if !mapChars[c] {
			return false
		}
	}

	return true
}

// <END-OF-CODE>
