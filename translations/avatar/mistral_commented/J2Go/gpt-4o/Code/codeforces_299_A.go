package main

import (
	"fmt"
	"sort"
)

func main() {
	var n int
	fmt.Scan(&n) // Reading the number of elements in the array from the user input
	a := make([]int, n) // Creating a slice of integers of size n

	// Initializing the slice with user input
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i]) // Reading an integer value from the user input and storing it in the slice at the current index
	}

	sort.Ints(a) // Sorting the slice in ascending order

	min := a[0] // Assigning the minimum value in the slice to the min variable

	// Checking if all the elements in the slice are multiples of the minimum value
	for _, value := range a {
		if value%min != 0 { // Checking if the current element is not a multiple of the minimum value
			fmt.Println(-1) // Printing -1 if any non-multiple of the minimum value is found
			return // Exiting the function if any non-multiple of the minimum value is found
		}
	}

	// Printing the minimum value if all elements are multiples of the minimum value
	fmt.Println(min)
}

// <END-OF-CODE>
