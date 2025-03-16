
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Main function starts here
func main() {
	// Initialize variables
	var N, T int // N is the number of elements in the array A, T is an input value

	// Read input values from the standard input
	reader := bufio.NewReader(os.Stdin)
	N, _ = strconv.Atoi(reader.Scan())
	T, _ = strconv.Atoi(reader.Scan())

	// Allocate memory for an integer array A of size N
	A := make([]int, N)

	// Allocate memory for a vector B of size N
	B := make([]int, N)

	// Read integer values from the standard input and store them in array A
	for i := 0; i < N; i++ {
		A[i], _ = strconv.Atoi(reader.Scan())
	}

	// Initialize variable m with the minimum value among the first two elements of array A
	m := A[0]
	if A[1] < m {
		m = A[1]
	}

	// Set the first element of vector B with the difference between the second element of array A and the initialized value of m
	B[1] = A[1] - m

	// Iterate through the remaining elements of array A starting from the third one
	for i := 2; i < N; i++ {
		// Update the value of m with the minimum value between it and the current element of array A
		m = min(m, A[i])

		// Set the current element of vector B with the difference between the current element of array A and the updated value of m
		B[i] = A[i] - m
	}

	// Print the output value to the standard output
	fmt.Println(count(B, *max_element(B)))

	// End of main function
}

// Function to find the minimum value between two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// Function to count the occurrences of a specific value in an array
func count(arr []int, val int) int {
	count := 0
	for _, v := range arr {
		if v == val {
			count++
		}
	}
	return count
}

// Function to find the maximum element in an array
func max_element(arr []int) int {
	max := arr[0]
	for _, v := range arr {
		if v > max {
			max = v
		}
	}
	return max
}

// Translate the above Go code to Rust and end with comment "