package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Create a Scanner object to read input from the user
	scanner := bufio.NewScanner(os.Stdin)
	
	// Read the input string from the user
	scanner.Scan()
	s := scanner.Text()
	
	// Convert the input string to a character array
	targ := []rune(s)
	
	// Initialize a map to store the frequency of each character
	freqMap := make(map[rune]int)
	
	// Loop through each character in the array
	for _, char := range targ {
		// If the character is not already in the map, add it with a count of 1
		if _, exists := freqMap[char]; !exists {
			freqMap[char] = 1
		} else {
			// If the character is already in the map, increment its count
			freqMap[char]++
		}
	}
	
	// Initialize a boolean variable to check if the conditions are met
	ok := true
	
	// Check if each character appears exactly twice
	for _, count := range freqMap {
		if count != 2 {
			ok = false // Set ok to false if any character does not appear twice
			break
		}
	}
	
	// Check if there are exactly two unique characters that appear twice
	if ok && len(freqMap) == 2 {
		fmt.Println("Yes") // Output "Yes" if conditions are satisfied
	} else {
		fmt.Println("No") // Output "No" if conditions are not satisfied
	}
}

