package main

import (
	"fmt"
)

// Function to print the array elements
func white(n int, A []int) {
	for i := 0; i < n-1; i++ {
		fmt.Print(A[i], " ")
	}
	fmt.Println(A[n-1])
}

// Function to perform insertion sort on the array
func insertionsort(n int, A []int) {
	var a int
	for i := 0; i < n; i++ {
		for j := 0; j < i; j++ {
			if A[i] < A[j] {
				// Swap A[i] and A[j]
				a = A[i]
				A[i] = A[j]
				A[j] = a
			}
		}
		// Print the array after each insertion
		white(n, A)
	}
}

// Main function to handle input and call the sorting function
func main() {
	var i, n int
	var A [100]int
	fmt.Scan(&n)
	for i = 0; i < n; i++ {
		fmt.Scan(&A[i])
	}
	insertionsort(n, A[:])
}

