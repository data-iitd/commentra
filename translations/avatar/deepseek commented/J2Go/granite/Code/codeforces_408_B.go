

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

	if isValid(s1, s2) == false {
		fmt.Println(-1)
	} else {
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
			if _, ok := hs[c];!ok {
				hs[c] = true
				x1 := m1[c]
				x2 := m2[c]
				x1 = int(math.Min(float64(x1), float64(x2)))
				ans += x1
			}
		}

		fmt.Println(ans)
	}
}

func isValid(s1 string, s2 string) bool {
	n1 := len(s1)
	n2 := len(s2)
	map := make(map[rune]bool)

	for _, c := range s1 {
		map[c] = true
	}

	for _, c := range s2 {
		if _, ok := map[c];!ok {
			return false
		}
	}

	return true
}

// 