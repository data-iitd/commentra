
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
		fmt.Println(minFreq(s1, s2))
	} else {
		fmt.Println(-1)
	}
}

func isValid(s1, s2 string) bool {
	for _, c := range s1 {
		if!strings.Contains(s2, string(c)) {
			return false
		}
	}
	return true
}

func minFreq(s1, s2 string) int {
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
		if!hs[c] {
			hs[c] = true
			x1 := m1[c]
			x2 := m2[c]
			x1 = min(x1, x2)
			ans += x1
	}
	return ans
}

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

