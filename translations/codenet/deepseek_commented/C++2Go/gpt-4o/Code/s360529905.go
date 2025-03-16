package main

import (
	"fmt"
	"sort"
)

func main() {
	var N int
	fmt.Scan(&N) // Read the number of elements from the user

	a := make([]int, N) // Create a slice for array a
	b := make([]int, N) // Create a slice for array b

	for i := 0; i < N; i++ { // Loop to read elements into array a and copy them to array b
		fmt.Scan(&a[i]) // Read an element into array a
		b[i] = a[i]     // Copy the element from array a to array b
	}

	sort.Ints(b) // Sort array b

	var frontHalf, backHalf int
	frontHalf = b[N/2-1] // Calculate the first half's middle value
	backHalf = b[N/2]    // Calculate the second half's middle value

	for i := 0; i < N; i++ { // Loop to compare each element of array a
		if a[i] < backHalf { // Check if the element is less than the second middle value
			fmt.Println(backHalf) // Print the second middle value
		} else {
			fmt.Println(frontHalf) // Print the first middle value
		}
	}
}

// <END-OF-CODE>
