
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func isLatinLetter(c rune) bool {
	return c >= 'a' && c <= 'z'
}

func isPunctuation(c rune) bool {
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
	fmt.Print("Enter a string: ")
	text, _ := reader.ReadString('\n')
	text = strings.TrimSpace(text)
	var result strings.Builder
	result.WriteString(string(text[0]))
	for i := 1; i < len(text); i++ {
		c := text[i]
		if isLatinLetter(c) {
			if!isLatinLetter(text[i-1]) {
				result.WriteString(" ")
			}
			result.WriteString(string(c))
		} else if isPunctuation(c) {
			result.WriteString(string(c))
		}
	}
	fmt.Println(result.String())
}

