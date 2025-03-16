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
	if c == '.' {
		return true
	}
	if c == ',' {
		return true
	}
	if c == '!' {
		return true
	}
	if c == '?' {
		return true
	}
	return false
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	s, _ := reader.ReadString('\n')
	s = strings.TrimSuffix(s, "\n")
	sb := strings.Builder{}
	sb.WriteByte(s[0])
	for i := 1; i < len(s); i++ {
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
	fmt.Fprintln(writer, sb.String())
}

