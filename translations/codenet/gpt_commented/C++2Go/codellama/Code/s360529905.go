package main

import (
	"fmt"
	"sort"
)

func main() {
	// Declare pointers for the arrays and variables for loop index and size
	var a, b []int
	i, N := 0, 0
	frontHalf, backHalf := 0, 0

	// Read the number of elements
	fmt.Scanf("%d", &N)

	// Dynamically allocate memory for two arrays of size N
	a = make([]int, N)
	b = make([]int, N)

	// Read elements into array 'a' and copy them to array 'b'
	for i = 0; i < N; i++ {
		fmt.Scanf("%d", &a[i]) // Read element into array 'a'
		b[i] = a[i]            // Copy element from 'a' to 'b'
	}

	// Sort the array 'b' to find the median values
	sort.Ints(b)

	// Determine the two middle values (for even-sized arrays)
	frontHalf = b[N/2-1] // Value just before the median
	backHalf = b[N/2]    // Median value

	// Free the memory allocated for array 'b'
	b = nil

	// Output the appropriate value based on the original array 'a'
	for i = 0; i < N; i++ {
		// If the current element is less than the backHalf (median), print backHalf
		if a[i] < backHalf {
			fmt.Printf("%d\n", backHalf)
		} else { // Otherwise, print frontHalf
			fmt.Printf("%d\n", frontHalf)
		}
	}

	// Free the memory allocated for array 'a'
	a = nil

	// Indicate successful completion of the program
	fmt.Println("