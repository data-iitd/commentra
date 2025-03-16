
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a Scanner object to read input from the console
	reader := bufio.NewReader(os.Stdin)

	// Read the number of strings to be processed
	N, _ := strconv.Atoi(reader.ReadLine()[2 : len(reader.ReadLine())])

	// Initialize a map to store the strings with their corresponding indices
	map := make(map[int]string)

	// Read N strings from the input and store them in the map
	for i := 0; i < N; i++ {
		input := reader.ReadLine()
		map[i] = string(input[2 : len(input)])
	}

	// Initialize a boolean variable to track if the conditions are met
	ans := true

	// Initialize a map to keep track of previously seen strings
	past := make(map[int]string)

	// Variable to hold the last character of the previous string
	next := ""

	// Iterate through the strings to check the conditions
	for i := 0; i < N; i++ {
		// Check if the current string has already been seen
		if _, ok := past[i]; ok {
			ans = false // Set answer to false if a duplicate is found
			break
		}

		// Store the current string in the past map
		past[i] = map[i]

		// Check if this is not the first string
		if i!= 0 {
			// Check if the first character of the current string matches the last character of the previous string
			if!strings.EqualFold(string(map[i][0]), next) {
				ans = false // Set answer to false if the characters do not match
				break
			}
		}

		// Update 'next' to the last character of the current string
		next = string(map[i][len(map[i])-1])
	}

	// Output the result based on the value of ans
	if ans {
		fmt.Println("Yes") // Print "Yes" if all conditions are satisfied
	} else {
		fmt.Println("No") // Print "No" if any condition fails
	}
}
