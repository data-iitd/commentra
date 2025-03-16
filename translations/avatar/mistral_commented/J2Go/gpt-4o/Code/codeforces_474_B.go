package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n) // Reading the number of elements in the array from the input
	arr := make([]int, n) // Creating an integer slice of size n
	fmt.Scan(&arr[0]) // Reading the first element of the array from the input

	// Initializing a for loop to read and store the remaining elements of the array
	for i := 1; i < n; i++ {
		var x int
		fmt.Scan(&x) // Reading an element from the input
		arr[i] = x + arr[i-1] // Assigning the current element the sum of the previous element and the current input
	}

	var m int
	fmt.Scan(&m) // Reading the number of queries from the input
	q := make([]int, m) // Creating an integer slice of size m to store the queries

	// Initializing a for loop to read and store the queries in the slice q
	for i := 0; i < m; i++ {
		fmt.Scan(&q[i]) // Reading a query from the input
	}

	// Initializing a for loop to process each query and print the result
	for k := 0; k < m; k++ {
		fmt.Println(fun(arr, q[k], n) + 1) // Calling the fun function with the slice, query, and size of the slice as arguments and printing the result with an offset of 1
	}
}

// fun function takes a slice, a query, and the size of the slice as arguments
func fun(arr []int, q int, n int) int {
	res := 0 // Initializing a variable to store the result
	i, j := 0, n // Initializing two variables to represent the left and right indices of the slice

	// Using a while loop to perform a binary search on the slice
	for i <= j {
		md := i + (j-i)/2 // Calculating the middle index of the subarray
		if arr[md] == q { // If the middle element is equal to the query, return the middle index
			return md
		} else if arr[md] > q { // If the middle element is greater than the query, update the result and shift the right index towards the left
			res = md
			j = md - 1
		} else { // If the middle element is less than the query, shift the left index towards the right
			i = md + 1
		}
	}

	// If the query is not present in the slice, return the index where it should be inserted
	return res
}

// <END-OF-CODE>
