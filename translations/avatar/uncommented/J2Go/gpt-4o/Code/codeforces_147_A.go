package main

import (
	"bufio"
	"fmt"
	"os"
)

func isLatinLetter(c rune) bool {
	return c >= 'a' && c <= 'z'
}

func isPunctuation(c rune) bool {
	return c == '.' || c == ',' || c == '!' || c == '?'
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	s, _ := reader.ReadString('\n')

	var sb []rune
	n := len(s)
	if n > 0 {
		sb = append(sb, rune(s[0]))
	}

	for i := 1; i < n; i++ {
		c := rune(s[i])
		if isLatinLetter(c) {
			if !isLatinLetter(rune(s[i-1])) {
				sb = append(sb, ' ')
			}
			sb = append(sb, c)
		} else if isPunctuation(c) {
			sb = append(sb, c)
		}
	}

	fmt.Println(string(sb))
}

// <END-OF-CODE>
