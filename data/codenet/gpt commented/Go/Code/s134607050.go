package main

import (
	"fmt"
)

// searchRange finds the range of indices in the text where 'R' and 'L' are located.
// It returns the start index, the middle index (first non-'R' character), and the end index (first non-'L' character).
func searchRange(text *string, start, limit int) (int, int, int) {
	middle := -1

	// Find the first index where the character is not 'R'
	for i := start; i < limit; i++ {
		if (*text)[i] != 'R' {
			middle = i
			break
		}
	}

	end := limit

	// Find the first index after 'middle' where the character is not 'L'
	for i := middle; i < limit; i++ {
		if (*text)[i] != 'L' {
			end = i
			break
		}
	}

	// Return the start, middle, and end indices
	return start, middle, end
}

// answer processes the input text and prints the results based on the 'R' and 'L' characters.
func answer() {
	var text string
	// Read input text from standard input
	fmt.Scan(&text)
	limit := len(text)

	start := 0
	middle := 0
	end := 0
	firstPrinted := false

	// Loop until the end of the text is reached
	for end < limit {
		// Get the range of indices for the current segment of 'R's and 'L's
		start, middle, end = searchRange(&text, start, limit)
		len1 := middle - start
		len2 := end - middle

		// Print '0's for the 'R' segment
		for i := start; i < middle-1; i++ {
			if firstPrinted {
				fmt.Print(" ")
			}
			fmt.Print("0")
			firstPrinted = true
		}

		// Calculate counts based on the lengths of the segments
		count1 := (len1+1)/2 + len2/2
		count2 := len1/2 + (len2+1)/2

		// Print the counts for the current segment
		if firstPrinted {
			fmt.Print(" ")
		}
		fmt.Printf("%v %v", count1, count2)
		firstPrinted = true

		// Print '0's for the 'L' segment
		for i := middle + 1; i < end; i++ {
			if firstPrinted {
				fmt.Print(" ")
			}
			fmt.Print("0")
			firstPrinted = true
		}
		// Move to the next segment
		start = end
		firstPrinted = true
	}
	// Print a newline at the end of the output
	fmt.Println()
}

// main function serves as the entry point of the program
func main() {
	answer()
}
