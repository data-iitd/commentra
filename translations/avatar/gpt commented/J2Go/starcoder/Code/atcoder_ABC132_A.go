package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	// Read input from stdin
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter a string: ")
	input, _ := reader.ReadString('\n')

	// Convert the input string to a character array
	targ := []rune(strings.TrimSpace(input))

	// Initialize a map to store the frequency of each character
	var map map[rune]int
	map = make(map[rune]int)

	// Loop through each character in the array
	for _, c := range targ {
		// If the character is not already in the map, add it with a count of 1
		if _, ok := map[c];!ok {
			map[c] = 1
		} else {
			// If the character is already in the map, increment its count
			map[c]++
		}
	}

	// Initialize a boolean variable to check if the conditions are met
	ok := true

	// Check if each character appears exactly twice
	for _, v := range map {
		if v!= 2 {
			ok = false // Set ok to false if any character does not appear twice
			break
		}
	}

	// Check if there are exactly two unique characters that appear twice
	if ok && len(map) == 2 {
		fmt.Println("Yes") // Output "Yes" if conditions are satisfied
	} else {
		fmt.Println("No") // Output "No" if conditions are not satisfied
	}
}

