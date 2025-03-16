package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n) // Reading the number of elements in the array from user input
	array := make([]int, n+1) // Creating a slice of size n+1 to store the input elements

	// Reading the elements of the array from user input
	for i := 1; i <= n; i++ {
		fmt.Scan(&array[i]) // Reading the i-th element of the array
	}

	odd, even := 0, 0
	oddInd, evenInd := 0, 0 // Initializing variables for counting odd and even elements and their indices

	// Counting the number of odd and even elements and storing their indices
	for i := 1; i <= n; i++ {
		if array[i]%2 == 0 { // If the current element is even
			even++          // Increment the count of even elements
			evenInd = i     // Store the index of the current even element
		} else { // If the current element is odd
			odd++          // Increment the count of odd elements
			oddInd = i     // Store the index of the current odd element
		}
	}

	// Determining the output based on the count of odd and even elements
	if odd > even { // If there are more odd elements than even elements
		fmt.Println(evenInd) // Print the index of the last even element
	} else { // If there are more even elements than odd elements
		fmt.Println(oddInd) // Print the index of the last odd element
	}
}

// <END-OF-CODE>
