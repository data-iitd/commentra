
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func isLatinLetter(c byte) bool {
	return c >= 'a' && c <= 'z'
}

func isPunctuation(c byte) bool {
	return c == '.' || c == ',' || c == '!' || c == '?'
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	s, _ := reader.ReadString('\n')
	s = strings.TrimSuffix(s, "\n")
	n := len(s)
	sb := strings.Builder{}
	sb.WriteByte(s[0])
	for i := 1; i < n; i++ {
		c := s[i]
		if isLatinLetter(c) {
			if!isLatinLetter(s[i-1]) {
				sb.WriteByte(' ')
			}
			sb.WriteByte(c)
		} else if isPunctuation(c) {
			sb.WriteByte(c)
		}
	}
	fmt.Println(sb.String())
}

