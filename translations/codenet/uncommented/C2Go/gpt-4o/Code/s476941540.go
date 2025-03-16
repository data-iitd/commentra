package main

import (
	"fmt"
	"os"
	"bufio"
	"unicode"
)

func main() {
	alpha := make([]int, 26)

	reader := bufio.NewReader(os.Stdin)

	for {
		ch, _, err := reader.ReadRune()
		if err != nil {
			break
		}

		if unicode.IsLetter(ch) {
			if unicode.IsUpper(ch) {
				alpha[ch-'A']++
			} else {
				alpha[ch-'a']++
			}
		}
	}

	for i := 0; i < 26; i++ {
		fmt.Printf("%c : %d\n", 'a'+rune(i), alpha[i])
	}
}

// <END-OF-CODE>
