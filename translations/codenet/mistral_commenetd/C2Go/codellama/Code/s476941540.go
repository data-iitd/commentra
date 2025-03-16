package main

import (
	"fmt"
	"unicode"
)

func main() {
	var i int
	var alpha [26]int
	var ch rune

	for i = 0; i < 26; i++ {
		alpha[i] = 0
	}

	for {
		ch = rune(getchar())
		if ch == EOF {
			break
		}
		if unicode.IsLetter(ch) {
			if unicode.IsUpper(ch) {
				alpha[ch-65]++
			} else {
				alpha[ch-97]++
			}
		}
	}

	ch = 'a'
	for i = 0; i < 26; i++ {
		fmt.Printf("%c : %d\n", ch, alpha[i])
		ch++
	}
}

