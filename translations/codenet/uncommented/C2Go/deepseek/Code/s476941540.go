package main

import (
	"bufio"
	"fmt"
	"os"
	"unicode"
)

func main() {
	var alpha [26]int
	var ch rune

	for i := 0; i < 26; i++ {
		alpha[i] = 0
	}

	reader := bufio.NewReader(os.Stdin)
	for {
		ch, _, err := reader.ReadRune()
		if err != nil {
			break
		}

		if unicode.IsLetter(ch) {
			if unicode.IsUpper(ch) {
				alpha[ch - 'A']++
			} else {
				alpha[ch - 'a']++
			}
		}
	}

	for i := 0; i < 26; i++ {
		ch = rune('a' + i)
		fmt.Printf("%c : %d\n", ch, alpha[i])
	}
}

