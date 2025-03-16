package main

import (
	"fmt"
	"sort"
)

func cutRibbon() {
	var length int
	var a, b, c int

	// Read input and convert it into integers
	fmt.Scan(&length, &a, &b, &c)

	// Create a slice to hold the piece lengths
	pieces := []int{a, b, c}
	// Sort the piece lengths in ascending order
	sort.Ints(pieces)

	// If the total length is divisible by the smallest piece length, print the maximum number of pieces
	if length%pieces[0] == 0 {
		fmt.Println(length / pieces[0])
		return
	}

	// Initialize the answer variable to keep track of the maximum pieces
	ans := 0

	// Case when the two smallest piece lengths are equal
	if pieces[0] == pieces[1] {
		for i := 0; i <= length/pieces[2]; i++ {
			check := length - i*pieces[2]
			if check >= 0 && check%pieces[0] == 0 {
				k := check / pieces[0]
				ans = max(ans, k+i)
			}
		}
	} else {
		// Case when the two smallest piece lengths are different
		for i := 0; i <= length/pieces[2]; i++ {
			for j := 0; j <= length/pieces[1]; j++ {
				check := length - i*pieces[2] - j*pieces[1]
				if check >= 0 && check%pieces[0] == 0 {
					k := check / pieces[0]
					ans = max(ans, k+i+j)
				}
			}
		}
	}

	// Print the maximum number of pieces that can be obtained
	fmt.Println(ans)
}

// Helper function to find the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	// Call the function to execute the ribbon cutting logic
	cutRibbon()
}

// <END-OF-CODE>
