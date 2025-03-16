
package main

import (
	"bufio"
	"bytes"
	"fmt"
	"os"
	"sort"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	t, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(t)

	for i := 0; i < n; i++ {
		s, _ := reader.ReadString('\n')
		s = s[:len(s)-1]

		m := make(map[string]bool)
		m[s] = true

		for j := 1; j < len(s); j++ {
			var buf bytes.Buffer
			for k := 0; k < j; k++ {
				buf.WriteString(string(s[k]))
			}
			s1 := buf.String()
			reverse(&s1)

			var buf2 bytes.Buffer
			for k := j; k < len(s); k++ {
				buf2.WriteString(string(s[k]))
			}
			s2 := buf2.String()
			reverse(&s2)

			m[s1+s2] = true
			m[s2+s1] = true

			m[s1+s] = true
			m[s+s1] = true

			m[s+s2] = true
			m[s2+s] = true
		}

		fmt.Println(len(m))
	}
}

func reverse(s *string) {
	runes := []rune(*s)
	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	*s = string(runes)
}

