

package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	t, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(strings.TrimSpace(t))

	for i := 0; i < n; i++ {
		s, _ := reader.ReadString('\n')
		s = strings.TrimSpace(s)

		m := make(map[string]bool)

		for j := 1; j < len(s); j++ {
			a := s[:j]
			b := s[j:]

			m[a+b] = true
			m[b+a] = true
			m[a+reverse(b)] = true
			m[reverse(b)+a] = true
			m[reverse(a)+b] = true
			m[b+reverse(a)] = true
			m[reverse(a)+reverse(b)] = true
			m[reverse(b)+reverse(a)] = true
		}

		fmt.Println(len(m))
	}
}

func reverse(s string) string {
	runes := []rune(s)
	for i, j := 0, len(runes)-1; i < len(runes)/2; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	return string(runes)
}

