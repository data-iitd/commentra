package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Main function is the entry point of the program
func main() {
	// Creating a new scanner object to read input from the console
	sc := bufio.NewScanner(os.Stdin)

	// Reading the number of elements in the array from the input
	n, _ := strconv.Atoi(sc.Text())

	// Creating an integer array of size n
	arr := make([]int, n)

	// Reading the first element of the array from the input
	arr[0], _ = strconv.Atoi(sc.Text())

	// Initializing a for loop to read and store the remaining elements of the array
	for i := 1; i < n; i++ {
		// Reading an element from the input
		x, _ := strconv.Atoi(sc.Text())

		// Assigning the current element the sum of the previous element and the current input
		arr[i] = x + arr[i-1]
	}

	// Reading the number of queries from the input
	m, _ := strconv.Atoi(sc.Text())

	// Creating an integer array of size m to store the queries
	q := make([]int, m)

	// Initializing a for loop to read and store the queries in the array q
	for i := 0; i < m; i++ {
		// Reading a query from the input
		q[i], _ = strconv.Atoi(sc.Text())
	}

	// Initializing a for loop to process each query and print the result
	for k := 0; k < m; k++ {
		// Calling the fun function with the array, query, size of the array, and number of queries as arguments and printing the result with an offset of 1
		fmt.Println(fun(arr, q[k], n, m) + 1)
	}
}

// fun function takes an array, a query, the size of the array, and the number of queries as arguments
func fun(arr []int, q int, n int, m int) int {
	res := 0 // Initializing a variable to store the result
	i := 0   // Initializing a variable to represent the left index of the array
	j := n   // Initializing a variable to represent the right index of the array

	// Using a while loop to perform a binary search on the array
	for i <= j {
		md := i + (j-i)/2 // Calculating the middle index of the subarray
		if arr[md] == q {  // If the middle element is equal to the query, return the middle index
			return md
		} else if arr[md] > q {
			res = md // If the middle element is greater than the query, update the result and shift the right index towards the left
			j = md - 1
		} else {
			i = md + 1 // If the middle element is less than the query, shift the left index towards the right
		}
	}

	// If the query is not present in the array, return the index where it should be inserted
	return res
}

