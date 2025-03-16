
package main

import (
	"fmt"
)

// Function to search the range of 'R' and 'L' in the given text
// S....M....E
// R...RL...LR
func searchRange(text *string, start, limit int) (int, int, int) {
	middle := -1 // Initialize middle to -1

	for i := start; i < limit; i++ {
		if (*text)[i] != 'R' { // Check if current character is not 'R'
			middle = i // If not, then set middle to current index
			break // and break the loop
		}
	}

	end := limit // Initialize end to limit

	for i := middle; i < limit; i++ {
		if (*text)[i] != 'L' { // Check if current character is not 'L'
			end = i // If not, then set end to current index
			break // and break the loop
		}
	}

	return start, middle, end // Return start, middle and end indices
}

// Function to print the answer
func answer() {
	var text string // Initialize text as empty string
	fmt.Scan(&text) // Read text from standard input
	limit := len(text) // Get length of text

	start := 0 // Initialize start index to 0
	middle := 0 // Initialize middle index to 0
	end := 0 // Initialize end index to 0
	firstPrinted := false // Initialize firstPrinted to false

	for end < limit { // Loop until end is less than limit
		start, middle, end = searchRange(&text, start, limit) // Call searchRange function to find the range of 'R' and 'L'

		len1 := middle - start // Calculate length of first substring
		len2 := end - middle // Calculate length of second substring

		// Print the first substring
		for i := start; i < middle-1; i++ {
			if firstPrinted { // Check if firstPrinted is true
				fmt.Print(" ") // Print a space if true
			}
			fmt.Print("0") // Print '0' for each character in the first substring
			firstPrinted = true // Set firstPrinted to true
		}

		// Print the count of 'R' and 'L' in the first and second substrings
		if firstPrinted { // Check if firstPrinted is true
			fmt.Print(" ") // Print a space if true
		}
		fmt.Printf("%v %v", len1/2+len2/2, len1/2+(len2+1)/2) // Print the count of 'R' and 'L' in the first and second substrings
		firstPrinted = true // Set firstPrinted to true

		// Print the second substring
		for i := middle + 1; i < end; i++ {
			if firstPrinted { // Check if firstPrinted is true
				fmt.Print(" ") // Print a space if true
			}
			fmt.Print("0") // Print '0' for each character in the second substring
			firstPrinted = true // Set firstPrinted to true
		}
		start = end // Set start to end
		firstPrinted = true // Set firstPrinted to true
	}
	fmt.Println() // Print newline at the end
}

// Main function to call answer function
func main() {
	answer() // Call answer function
}

