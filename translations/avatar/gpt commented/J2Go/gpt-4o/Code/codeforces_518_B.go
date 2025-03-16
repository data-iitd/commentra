package main

import (
	"fmt"
	"strings"
)

func main() {
	var s, t string
	fmt.Scan(&s, &t)

	ura := 0
	opa := 0

	// Create a map to count occurrences of each character in string t
	tmap := make(map[rune]int)

	// Populate the character frequency map for string t
	for _, ch := range t {
		tmap[ch]++
	}

	// First pass: Replace characters in s with 'Я' and update the frequency map
	for i, ch := range s {
		num, exists := tmap[ch]
		if !exists {
			continue
		}
		if num == 1 {
			delete(tmap, ch)
		} else {
			tmap[ch]--
		}
		s = strings.Replace(s, string(ch), "Я", 1)
		ura++
	}

	// Second pass: Check for reversed characters and update the frequency map
	for _, ch := range s {
		rch := reverse(ch)
		num, exists := tmap[rch]
		if !exists {
			continue
		}
		if num == 1 {
			delete(tmap, rch)
		} else {
			tmap[rch]--
		}
		opa++
	}

	// Output the counts of unique character replacements and reversed characters
	fmt.Println(ura, opa)
}

// Method to reverse the case of a character
func reverse(ch rune) rune {
	if ch >= 'a' && ch <= 'z' {
		return ch - 'a' + 'A'
	} else if ch >= 'A' && ch <= 'Z' {
		return ch - 'A' + 'a'
	}
	return ch
}
