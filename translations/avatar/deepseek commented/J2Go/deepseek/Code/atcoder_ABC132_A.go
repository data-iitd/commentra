package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter a string: ")
	input, _ := reader.ReadString('\n')

	// Remove the newline character from the input
	input = input[:len(input)-1]

	// Convert the string to a character array
	targ := []rune(input)

	// Initialize a map to store character counts
	map := make(map[rune]int)

	// Loop through each character in the character array
	for _, char := range targ {
		// If the character is not already in the map, add it with a count of 1
		if _, exists := map[char]; !exists {
			map[char] = 1
		} else {
			// If the character is already in the map, increment its count
			map[char]++
		}
	}

	ok := true

	// Loop through each entry in the map
	for _, count := range map {
		// If any character count is not 2, set ok to false
		if count != 2 {
			ok = false
			break
		}
	}

	// Check if all characters appear exactly twice and there are exactly 2 unique characters
	if ok && len(map) == 2 {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

