package main

import (
	"fmt"
)

func main() {
	// Initialize variables
	var n, a, b int
	fmt.Scan(&n) // Read the number of test cases
	fmt.Scan(&a) // Read the number of elements in the first list
	fmt.Scan(&b) // Read the number of elements in the second list

	// Create slices to store the lists
	list1 := make(map[int]struct{}) // Using a map for efficient lookup
	list2 := make([]int, b)

	// Read and store the elements of the first list
	for i := 0; i < a; i++ {
		var element int
		fmt.Scan(&element) // Read an element
		list1[element] = struct{}{} // Add element to list1
	}

	// Read and store the elements of the second list
	for i := 0; i < b; i++ {
		fmt.Scan(&list2[i]) // Read an element into list2
	}

	// Iterate through the input array and print the corresponding number based on the presence of the element in list1
	for i := 1; i <= n; i++ {
		if _, exists := list1[i]; exists { // Check if the current input element is present in list1
			fmt.Print(1, " ") // If present, print 1
		} else {
			fmt.Print(2, " ") // If not present, print 2
		}
	}
	fmt.Println() // Print a newline at the end
}
