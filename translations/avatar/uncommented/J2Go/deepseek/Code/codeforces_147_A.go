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
	fmt.Fscanln(reader, &s)
	var sb strings.Builder
	n := len(s)
	sb.WriteByte(s[0])
	for i := 1; i < n; i++ {
		c := s[i]
		if isLatinLetter(c) {
			if !isLatinLetter(s[i-1]) {
				sb.WriteByte(' ')
			}
			sb.WriteByte(c)
		} else if isPunctuation(c) {
			sb.WriteByte(c)
		}
	}
	fmt.Println(sb.String())
}

