package main

import (
	"fmt"
	"strings"
)

func main() {
	// Create a Scanner object to read input from the user
	in := bufio.NewScanner(os.Stdin)

	// Read the input string from the user
	in.Scan()
	s := in.Text()

	// Convert the input string to a character array
	targ := []rune(s)

	// Initialize a HashMap to store the frequency of each character
	map := make(map[rune]int)

	// Loop through each character in the array
	for i := 0; i < len(targ); i++ {
		// If the character is not already in the map, add it with a count of 1
		if _, ok := map[targ[i]]; !ok {
			map[targ[i]] = 1
		} else {
			// If the character is already in the map, increment its count
			map[targ[i]]++
		}
	}

	// Initialize a boolean variable to check if the conditions are met
	ok := true

	// Check if each character appears exactly twice
	for c, v := range map {
		if v != 2 {
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

	// Close the scanner to prevent resource leaks
	in.Close()
}

