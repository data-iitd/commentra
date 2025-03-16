
package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	s1 := os.Args[1]
	s2 := os.Args[2]
	if !isValid(s1, s2) {
		fmt.Println(-1)
		return
	}
	m1 := make(map[rune]int)
	m2 := make(map[rune]int)
	for _, c := range s1 {
		if _, ok := m1[c]; ok {
			m1[c]++
		} else {
			m1[c] = 1
		}
	}
	for _, c := range s2 {
		if _, ok := m2[c]; ok {
			m2[c]++
		} else {
			m2[c] = 1
		}
	}
	ans := 0
	hs := make(map[rune]bool)
	for _, c := range s2 {
		if !hs[c] {
			hs[c] = true
			x1 := m1[c]
			x2 := m2[c]
			x1 = int(math.Min(float64(x1), float64(x2)))
			ans += x1
		}
	}
	fmt.Println(ans)
}

func isValid(s1, s2 string) bool {
	m := make(map[rune]bool)
	for _, c := range s1 {
		m[c] = true
	}
	for _, c := range s2 {
		if !m[c] {
			return false
		}
	}
	return true
}

