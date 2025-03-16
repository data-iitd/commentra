_
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	// Create a new Scanner to read input from stdin
	scanner := bufio.NewScanner(os.Stdin)
	// Read the first line of input from stdin
	scanner.Scan()
	// Split the input into a slice of strings, separated by a space
	s := strings.Split(scanner.Text(), " ")
	// Initialize a new StringBuilder with the first string
	s1 := strings.Builder{}
	s1.WriteString(s[0])
	// Read the second line of input from stdin
	scanner.Scan()
	// Split the input into a slice of strings, separated by a space
	t := strings.Split(scanner.Text(), " ")
	// Initialize a map to count the frequency of each character in string t
	tmap := make(map[rune]int)
	// Populate the character frequency map
	for _, ch := range t[0] {
		tmap[ch]++
	}
	// Initialize counters for unique character replacements and reversed characters
	ura := 0
	opa := 0
	// Get the length of the StringBuilder for iteration
	length := s1.Len()
	// First pass: Replace characters in s with 'Я' and update the frequency map
	for i := 0; i < length; i++ {
		ch := rune(s1.String()[i])
		num := tmap[ch]
		// If the character is not in the map, skip it
		if num == 0 {
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
		s1.WriteRune('Я')
		// Increment the unique character replacement counter
		ura++
	}
	// Second pass: Check for reversed characters and update the frequency map
	for i := 0; i < length; i++ {
		ch := rune(s1.String()[i])
		// Get the reversed character (lowercase to uppercase or vice versa)
		rch := reverse(ch)
		num := tmap[rch]
		// If the reversed character is not in the map, skip it
		if num == 0 {
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
		return rune(ch - 32)
	}
	// If it's uppercase, convert it to lowercase
	if ch >= 'A' && ch <= 'Z' {
		return rune(ch + 32)
	}
	// Otherwise, return the character
	return ch
}

