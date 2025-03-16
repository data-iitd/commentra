package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func isValid(s1, s2 string) bool {
	map1 := make(map[rune]bool)
	for _, c := range s1 {
		map1[c] = true
	}
	for _, c := range s2 {
		if _, ok := map1[c]; !ok {
			return false
		}
	}
	return true
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter first string: ")
	s1, _ := reader.ReadString('\n')
	s1 = strings.TrimSpace(s1)

	fmt.Print("Enter second string: ")
	s2, _ := reader.ReadString('\n')
	s2 = strings.TrimSpace(s2)

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
				x1 = x2
			}
			ans += x1
		}
	}
	fmt.Println(ans)
}
