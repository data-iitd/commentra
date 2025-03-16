package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	// Create a Scanner object to read input from the console
	scanner := bufio.NewScanner(os.Stdin)
	
	// Read the first string and initialize a StringBuilder with it
	scanner.Scan()
	s := strings.Builder{}
	s.WriteString(scanner.Text())
	
	// Read the second string
	scanner.Scan()
	t := scanner.Text()
	
	// Initialize counters for unique characters replaced (ura) and reversed characters (opa)
	ura := 0
	opa := 0
	
	// Create a map to count occurrences of each character in string t
	tmap := make(map[rune]int)
	
	// Populate the character frequency map for string t
	for _, ch := range t {
		tmap[ch]++
	}
	
	// Get the length of the StringBuilder for iteration
	length := s.Len()
	
	// Convert StringBuilder to a rune slice for easy manipulation
	runes := []rune(s.String())
	
	// First pass: Replace characters in s with 'Я' and update the frequency map
	for i := 0; i < length; i++ {
		ch := runes[i]
		if count, exists := tmap[ch]; exists && count > 0 {
			tmap[ch]--
			if tmap[ch] == 0 {
				delete(tmap, ch)
			}
			runes[i] = 'Я'
			ura++
		}
	}
	
	// Second pass: Check for reversed characters and update the frequency map
	for i := 0; i < length; i++ {
		ch := runes[i]
		rch := reverse(ch)
		if count, exists := tmap[rch]; exists && count > 0 {
			tmap[rch]--
			if tmap[rch] == 0 {
				delete(tmap, rch)
			}
			opa++
		}
	}
	
	// Output the counts of unique character replacements and reversed characters
	fmt.Println(ura, opa)
}

// Method to reverse the case of a character
func reverse(ch rune) rune {
	if ch >= 'a' && ch <= 'z' {
		return ch - 32
	} else if ch >= 'A' && ch <= 'Z' {
		return ch + 32
	}
	return ch
}

