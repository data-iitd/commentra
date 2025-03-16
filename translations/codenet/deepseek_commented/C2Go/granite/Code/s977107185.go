
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {

	N, _ := strconv.Atoi(readStdin()) // Read the size of the array

	A := make([]int, N) // Create an array of size N

	for i := 0; i < N; i++ {
		A[i], _ = strconv.Atoi(readStdin()) // Read the elements of the array
	}

	// Implement Bubble Sort
	count := 0 // Initialize the swap counter
	for i := 0; i < N-1; i++ {
		for j := N - 1; j > i; j-- {
			if A[j] < A[j-1] {
				tmp := A[j] // Swap A[j] and A[j-1]
				A[j] = A[j-1]
				A[j-1] = tmp
				count++ // Increment the swap counter
			}
		}
	}

	for i := 0; i < N; i++ {
		fmt.Print(A[i]) // Print the sorted array elements
		if i < N-1 {
			fmt.Print(" ") // Print a space between elements, but not after the last element
		}
	}

	fmt.Println() // Print a newline character to end the line

	fmt.Println(count) // Print the number of swaps

	// 