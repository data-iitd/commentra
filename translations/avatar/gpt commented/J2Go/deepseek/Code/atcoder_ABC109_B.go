package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Create a Scanner object to read input from the console
	scanner := bufio.NewScanner(os.Stdin)
	
	// Read the number of strings to be processed
	var N int
	fmt.Scan(&N)
	
	// Initialize a map to store the strings with their corresponding indices
	m := make(map[int]string)
	
	// Read N strings from the input and store them in the map
	for i := 0; i < N; i++ {
		scanner.Scan()
		m[i] = scanner.Text()
	}
	
	// Initialize a boolean variable to track if the conditions are met
	ans := true
	
	// Initialize a map to keep track of previously seen strings
	past := make(map[int]string)
	
	// Variable to hold the last character of the previous string
	var next string
	
	// Iterate through the strings to check the conditions
	for i := 0; i < N; i++ {
		// Check if the current string has already been seen
		for _, value := range past {
			if value == m[i] {
				ans = false // Set answer to false if a duplicate is found
				break
			}
		}
		if !ans {
			break
		}
		
		// Store the current string in the past map
		past[i] = m[i]
		
		// Check if this is not the first string
		if i != 0 {
			// Check if the first character of the current string matches the last character of the previous string
			if next != m[i][:1] {
				ans = false // Set answer to false if the characters do not match
				break
			}
		}
		
		// Update 'next' to the last character of the current string
		next = m[i][len(m[i])-1:]
	}
	
	// Output the result based on the value of ans
	if ans {
		fmt.Println("Yes") // Print "Yes" if all conditions are satisfied
	} else {
		fmt.Println("No") // Print "No" if any condition fails
	}
}
