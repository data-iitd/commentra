
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	// Create a Scanner object to read input from the console
	scan := bufio.NewScanner(os.Stdin)

	// Read the first string and initialize a StringBuilder with it
	s := strings.Builder{}
	s.WriteString(scan.Text())

	// Read the second string
	t := scan.Text()

	// Initialize counters for unique characters replaced (ura) and reversed characters (opa)
	ura := 0
	opa := 0

	// Create a map to count occurrences of each character in string t
	tmap := make(map[rune]int)

	// Populate the character frequency map for string t
	for _, ch := range t {
		// If the character is not already in the map, add it with a count of 1
		if _, ok := tmap[ch]; !ok {
			tmap[ch] = 1
		} else {
			// If it exists, increment its count
			tmap[ch]++
		}
	}

	// Get the length of the StringBuilder for iteration
	length := s.Len()

	// First pass: Replace characters in s with 'Я' and update the frequency map
	for i := 0; i < length; i++ {
		ch := s.String()[i]
		num, ok := tmap[ch]
		// If the character is not in the map, skip it
		if !ok {
			continue
		}
		inum := num
		// If the count is 1, remove it from the map; otherwise, decrement the count
		if inum == 1 {
			delete(tmap, ch)
		} else {
			tmap[ch] = inum - 1
		}
		// Replace the character in the StringBuilder with 'Я'
		s.Replace(i, i+1, "Я", 1)
		// Increment the unique character replacement counter
		ura++
	}

	// Second pass: Check for reversed characters and update the frequency map
	for i := 0; i < length; i++ {
		ch := s.String()[i]
		// Get the reversed character (lowercase to uppercase or vice versa)
		rch := reverse(ch)
		num, ok := tmap[rch]
		// If the reversed character is not in the map, skip it
		if !ok {
			continue
		}
		inum := num
		// If the count is 1, remove it from the map; otherwise, decrement the count
		if inum == 1 {
			delete(tmap, rch)
		} else {
			tmap[rch] = inum - 1
		}
		// Increment the reversed character counter
		opa++
	}

	// Output the counts of unique character replacements and reversed characters
	fmt.Println(ura, opa)
}

// Method to reverse the case of a character
func reverse(ch rune) rune {
	// If the character is lowercase, convert it to uppercase
	if ch >= 'a' && ch <= 'z' {
		return ch - 32
	} else {
		// If it's uppercase, convert it to lowercase
		return ch + 32
	}
}

