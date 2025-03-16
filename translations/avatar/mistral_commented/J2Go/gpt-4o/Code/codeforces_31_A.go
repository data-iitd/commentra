package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n) // Reading the number of elements in the array from standard input

	f := 0 // Initializing a flag variable to keep track of whether an element is found in the array
	a := make([]int, n) // Creating an integer slice of size n

	// Reading the elements of the array from standard input
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	// Outer loop to iterate through each element in the array
	for k := 0; k < n; k++ {
		t := a[k] // Storing the current element in a temporary variable

		// Inner loop to compare the current element with other elements in the array
		for i := 0; i < n; i++ {
			// Skipping the comparison if the current index is the same as the index of the current element
			if i != k {
				for j := 0; j < n; j++ { // Inner most loop to compare the current element with all the previous elements in the array
					if j != k && j != i && t == (a[i]+a[j]) { // Checking if the sum of the current and previous elements is equal to the current element
						f = 1 // Setting the flag variable to 1 if a match is found
						fmt.Println(k+1, j+1, i+1) // Printing the indices of the previous and current elements if a match is found
						break // Exiting the inner most loop if a match is found
					}
				}
				if f == 1 { // Checking if the flag variable is set to 1, indicating a match is found
					break // Exiting the inner loop if a match is found
				}
			}
		}
	}

	if f == 0 { // Checking if no match is found in the array
		fmt.Println("-1") // Printing "-1" if no match is found
	}
}

// <END-OF-CODE>
