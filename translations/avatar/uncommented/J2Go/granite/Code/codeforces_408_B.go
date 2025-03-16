
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	s := bufio.NewScanner(os.Stdin)
	s.Split(bufio.ScanWords)
	s.Scan()
	s1 := s.Text()
	s.Scan()
	s2 := s.Text()
	if isValid(s1, s2) == false {
		fmt.Println(-1)
	} else {
		m1 := make(map[string]int)
		m2 := make(map[string]int)
		for _, c := range s1 {
			m1[string(c)]++
		}
		for _, c := range s2 {
			m2[string(c)]++
		}
		ans := 0
		hs := make(map[string]bool)
		for _, c := range s2 {
			if!hs[string(c)] {
				hs[string(c)] = true
				x1 := m1[string(c)]
				x2 := m2[string(c)]
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
	map := make(map[string]bool)
	for _, c := range s1 {
		map[string(c)] = true
	}
	for _, c := range s2 {
		if!map[string(c)] {
			return false
		}
	}
	return true
}

// 