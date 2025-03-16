package main

import (
	"fmt"
	"sort"
)

func cutRibbon() {
	// Function to find the maximum number of pieces that can be cut from a ribbon of given length

	var arr [4]int
	// Take input as a list of integers
	for i := 0; i < 4; i++ {
		fmt.Scan(&arr[i])
	}

	// Assign the length of the ribbon to a variable
	length := arr[0]

	// Sort the next three elements of the array in ascending order
	sort.Ints(arr[1:])

	// Check if the length of the ribbon is divisible by the first element of the sorted list
	if length%arr[1] == 0 {
		// If it is, print the number of pieces required and return
		fmt.Println(length / arr[1])
		return
	}

	// Initialize an answer variable to keep track of the maximum number of pieces that can be cut
	ans := 0

	// If the first two elements of the sorted list are equal
	if arr[1] == arr[2] {
		// Initialize a variable k to keep track of the number of pieces required
		for i := 0; i <= length/arr[3]; i++ {
			// Check if the remaining length after subtracting i * arr[3] is divisible by arr[1]
			check := length - i*arr[3]
			if check >= 0 && check%arr[1] == 0 {
				k := check / arr[1]
				ans = max(ans, k+i)
			}
		}
	} else {
		// Double loop to find the maximum number of pieces that can be cut from the ribbon
		for i := 0; i <= length/arr[3]; i++ {
			for j := 0; j <= length/arr[2]; j++ {
				// Check if the remaining length after subtracting i * arr[3] and j * arr[2] is divisible by arr[1]
				check := length - i*arr[3] - j*arr[2]
				if check >= 0 && check%arr[1] == 0 {
					k := check / arr[1]
					ans = max(ans, k+i+j)
				}
			}
		}
	}

	// Print the final answer and return
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
	cutRibbon()
}

// <END-OF-CODE>
