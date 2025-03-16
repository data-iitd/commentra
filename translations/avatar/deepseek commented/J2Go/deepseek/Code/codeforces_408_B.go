package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func isValid(s1, s2 string) bool {
	map1 := make(map[rune]bool)

	// Populate the map with characters from s1
	for _, c := range s1 {
		map1[c] = true
	}

	// Check if all characters of s1 are present in s2
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

	// Check if the strings are valid using the isValid method
	if !isValid(s1, s2) {
		fmt.Println(-1)
		return
	}

	m1 := make(map[rune]int)
	m2 := make(map[rune]int)

	// Populate the HashMap with the frequency of each character in s1
	for _, c := range s1 {
		m1[c]++
	}

	// Populate the HashMap with the frequency of each character in s2
	for _, c := range s2 {
		m2[c]++
	}

	ans := 0
	hs := make(map[rune]bool)

	// Iterate over the characters of s2
	for _, c := range s2 {
		if !hs[c] {
			hs[c] = true
			x1 := m1[c]
			x2 := m2[c]
			x1 = min(x1, x2)
			ans += x1
		}
	}

	fmt.Println(ans)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

