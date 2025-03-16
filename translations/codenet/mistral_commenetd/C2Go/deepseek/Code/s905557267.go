package main

import (
	"fmt"
)

// Function to find the minimum of two integers
func min(a, b int) int {
	// If 'a' is less than or equal to 'b', return 'a'. Otherwise, return 'b'.
	if a <= b {
		return a
	}
	return b
}

// Function to check if there is a chain of 4 identical elements in the array 'b' of size 'n'
func Chain(b []int, n int) int {
	a := make([]int, n) // Create a copy of the input array 'b' to modify it in the function
	copy(a, b)          // Copy the elements from 'b' to 'a'

	// Check for chains of 4 identical elements in the array 'a'
	for i := 0; i < n-4; i++ {
		// If the current element is not zero and it is identical to the next three elements
		if a[i] != 0 && a[i] == a[i+1] && a[i] == a[i+2] && a[i] == a[i+3] {
			// Count the number of consecutive identical elements
			count := 0
			color := a[i]

			// Find the length of the chain and replace the identified elements with zeros
			for j := i; a[j] == color; j++ {
				a[j] = 0
				count++
			}

			// Swap the elements to maintain the order of the array
			for j := 0; i+j+count < n; j++ {
				buf := a[i+j]
				a[i+j] = a[i+j+count]
				a[i+j+count] = buf
			}
		}
	}

	// Count the number of unprocessed non-zero elements in the array 'a'
	count := 0
	for a[count] != 0 {
		count++
	}

	// If the count is 4 and all elements in the chain are identical, return 0
	if count == 4 && a[0] == a[1] && a[0] == a[2] && a[0] == a[3] {
		return 0
	}

	// Return the length of the longest chain found
	return count
}

// Main function to read the input and call the 'Chain' function
func main() {
	var n int
	for {
		// Initialize the array 'a' with zeros
		a := make([]int, 10000)
		for i := 0; i < 10000; i++ {
			a[i] = 0
		}

		// Read the number of elements in the current test case
		fmt.Scan(&n)
		if n == 0 {
			break
		}
		ans := n

		// Read the elements of the current test case
		for i := 0; i < n; i++ {
			fmt.Scan(&a[i])
		}

		// Find the longest chain in the current test case
		for i := 0; i < n-4; i++ {
			count := [3]int{0, 0, 0}
			for j := i; j < i+4; j++ {
				// Update the count array for the current element
				if a[j]-1 >= 0 {
					count[a[j]-1]++
				}
			}

			// Find the color of the chain
			color := 0
			for j := 0; j < 3; j++ {
				// If the count of the current color is greater than or equal to 3, set the color
				if count[j] >= 3 {
					color = j + 1
					break
				}
			}

			// If a chain of length 4 is found, update the answer
			if color != 0 {
				for j := i; j < i+4; j++ {
					buf := a[j]
					a[j] = color
					ans = min(ans, Chain(a, n))
					a[j] = buf
				}
			}
		}

		// Print the answer for the current test case
		fmt.Println(ans)
	}
}

