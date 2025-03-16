package main

import (
	"fmt"
	"sort"
)

func main() {
	var N int // Declare the number of elements
	fmt.Scanf("%d", &N) // Read the number of elements from the user
	a := make([]int, N) // Dynamically allocate memory for array a
	b := make([]int, N) // Dynamically allocate memory for array b

	for i := 0; i < N; i++ { // Loop to read elements into array a and copy them to array b
		fmt.Scanf("%d", &a[i]) // Read an element into array a
		b[i] = a[i] // Copy the element from array a to array b
	}

	sort.Ints(b) // Sort array b

	frontHalf := b[N/2-1] // Calculate the first half's middle value
	backHalf := b[N/2] // Calculate the second half's middle value

	// Free the dynamically allocated memory for array b
	b = nil

	for i := 0; i < N; i++ { // Loop to compare each element of array a
		if a[i] < backHalf { // Check if the element is less than the second middle value
			fmt.Println(backHalf) // Print the second middle value
		} else {
			fmt.Println(frontHalf) // Print the first middle value
		}
	}

	// Free the dynamically allocated memory for array a
	a = nil
}

