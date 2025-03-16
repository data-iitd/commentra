package main

import (
	"fmt"
)

func main() {
	var s string
	fmt.Scan(&s) // Read input string

	// Count occurrences of '0' and '1' at even and odd indices
	evenCount := map[rune]int{'0': 0, '1': 0}
	oddCount := map[rune]int{'0': 0, '1': 0}

	for i, char := range s {
		if i%2 == 0 {
			evenCount[char]++
		} else {
			oddCount[char]++
		}
	}

	// Calculate the minimum number of changes needed to make the string alternate
	option1 := len(s) - (evenCount['0'] + oddCount['1']) // Change all even indexed '0's to '1's and odd indexed '1's to '0's
	option2 := len(s) - (evenCount['1'] + oddCount['0']) // Change all even indexed '1's to '0's and odd indexed '0's to '1's

	// Print the minimum of the two options
	fmt.Println(min(option1, option2))
}

// Helper function to find the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// <END-OF-CODE>
