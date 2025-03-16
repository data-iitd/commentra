package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	s1, _ := reader.ReadString('\n')
	s2, _ := reader.ReadString('\n')
	s1 = strings.TrimSpace(s1)
	s2 = strings.TrimSpace(s2)
	if isValid(s1, s2) {
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
			if _, ok := hs[c];!ok {
				hs[c] = true
				x1 := m1[c]
				x2 := m2[c]
				x1 = min(x1, x2)
				ans += x1
			}
		}
		fmt.Println(ans)
	} else {
		fmt.Println(-1)
	}
}

func isValid(s1, s2 string) bool {
	n1 := len(s1)
	n2 := len(s2)
	m := make(map[rune]bool)
	for _, c := range s1 {
		m[c] = true
	}
	for _, c := range s2 {
		if _, ok := m[c];!ok {
			return false
		}
	}
	return true
}

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

