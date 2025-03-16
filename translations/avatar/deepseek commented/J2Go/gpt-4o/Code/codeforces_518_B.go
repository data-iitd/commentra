package main

import (
	"fmt"
	"strings"
)

func main() {
	var s string
	var t string
	fmt.Scan(&s, &t)

	// Step 1: Initialize counters for the number of replacements
	ura := 0 // Counter for replacements in step 3
	opa := 0 // Counter for replacements in step 4

	// Step 2: Create a frequency map `tmap` for characters in `t`.
	tmap := make(map[rune]int)
	for _, ch := range t {
		tmap[ch]++
	}

	// Step 3: Iterate through `s` and replace characters that are in `t` with 'Я'.
	length := len(s)
	sRunes := []rune(s) // Convert string to rune slice for mutability
	for i := 0; i < length; i++ {
		ch := sRunes[i]
		num, exists := tmap[ch]
		if !exists {
			continue
		}
		if num == 1 {
			delete(tmap, ch)
		} else {
			tmap[ch] = num - 1
		}
		sRunes[i] = 'Я'
		ura++
	}

	// Step 4: Iterate through `s` again and replace characters that are the reverse of characters in `t` with their reverse.
	for i := 0; i < length; i++ {
		ch := sRunes[i]
		rch := reverse(ch)
		num, exists := tmap[rch]
		if !exists {
			continue
		}
		if num == 1 {
			delete(tmap, rch)
		} else {
			tmap[rch] = num - 1
		}
		opa++
	}

	// Step 5: Print the results `ura` and `opa`.
	fmt.Println(ura, opa)
}

// Helper method to reverse the case of a character
func reverse(ch rune) rune {
	if ch >= 'a' && ch <= 'z' {
		return ch - 'a' + 'A'
	} else if ch >= 'A' && ch <= 'Z' {
		return ch - 'A' + 'a'
	}
	return ch
}

// <END-OF-CODE>
