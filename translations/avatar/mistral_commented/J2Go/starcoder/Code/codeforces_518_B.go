
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

// Main function
func main() {
	// Read input from stdin
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the first string: ")
	input, _ := reader.ReadString('\n')
	input = strings.Replace(input, "\n", "", -1)
	s := []rune(input)
	fmt.Println("Enter the second string: ")
	input, _ = reader.ReadString('\n')
	input = strings.Replace(input, "\n", "", -1)
	t := []rune(input)

	// Initialize counters for unique characters in the first string and opposite characters in the second string
	ura := 0
	opa := 0

	// Create a map to store the frequency of each character in the second string
	tmap := make(map[rune]int)

	// Read the characters of the second string and store their frequencies in the map
	for _, ch := range t {
		if _, ok := tmap[ch];!ok { // If the character is not already in the map
			tmap[ch] = 1
		} else {
			tmap[ch] = tmap[ch] + 1
		}
	}

	// Process the first string
	length := len(s)
	for i := 0; i < length; i++ {
		ch := s[i]
		num := tmap[ch]
		if num == 0 { // If the character is not in the second string
			continue
		}
		inum := num
		if inum == 1 { // If the character appears only once in the second string
			delete(tmap, ch)
		} else {
			tmap[ch] = inum - 1
		}
		s[i] = 'Я'
		ura++
	}

	// Process the reversed version of the first string
	for i := 0; i < length; i++ {
		ch := s[i]
		rch := reverse(ch) // Get the reverse character of the current character
		num := tmap[rch]
		if num == 0 { // If the reverse character is not in the second string
			continue
		}
		inum := num
		if inum == 1 { // If the reverse character appears only once in the second string
			delete(tmap, rch)
		} else {
			tmap[rch] = inum - 1
		}
		opa++
	}

	// Print the results
	fmt.Println(ura, opa)
}

// Reverse the given character
func reverse(ch rune) rune {
	if ch >= 'a' && ch <= 'z' { // If the character is lowercase
		return ch - 32 // Return its uppercase version
	} else if ch >= 'A' && ch <= 'Z' {
		return ch + 32 // If the character is uppercase, return its lowercase version
	}
	return ch
}

