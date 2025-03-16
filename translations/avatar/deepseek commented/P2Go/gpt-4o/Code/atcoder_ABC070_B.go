package main

import (
	"fmt"
	"sort"
)

func main() {
	var A [4]int

	// Taking input from the user and converting it into an array of integers
	for i := 0; i < 4; i++ {
		fmt.Scan(&A[i])
	}

	// Checking if the second element is less than or equal to the third element or if the fourth element is less than or equal to the first element
	if A[1] <= A[2] || A[3] <= A[0] {
		fmt.Println(0) // If either condition is true, print 0
	} else {
		sort.Ints(A[:]) // Sorting the array
		fmt.Println(A[2] - A[1]) // Printing the difference between the third and second elements
	}
}

// <END-OF-CODE>
