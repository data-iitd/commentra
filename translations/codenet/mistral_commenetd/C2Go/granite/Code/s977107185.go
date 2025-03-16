
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	var (
		i, j, N, tmp, count int
		A                      [100]int
	)

	// Read the number of elements in the array from user input
	fmt.Fscanf(bufio.NewReader(os.Stdin), "%d\n", &N)

	// Allocate memory for the array A and read its elements from user input
	for i = 0; i < N; i++ {
		fmt.Fscanf(bufio.NewReader(os.Stdin), "%d\n", &A[i]) // Read an element of the array A
	}

	// Perform bubble sort on the array A
	for i = 0; i < N-1; i++ {
		for j = N - 1; j > i; j-- { // Iterate through the array from last to first
			if A[j] < A[j-1] { // Check if the current element is smaller than the previous one
				tmp = A[j] // Swap the elements if they are in wrong order
				A[j] = A[j-1]
				A[j-1] = tmp
				count++ // Increment the counter for each swap
			}
		}
	}

	// Print the sorted array A
	for i = 0; i < N; i++ {
		fmt.Printf("%d", A[i]) // Print an element of the array A
		if i < N-1 {
			fmt.Print(" ") // Add a space between elements, except the last one
		}
	}

	fmt.Println() // Print a newline character after the sorted array

	// Print the number of swaps (count) made during sorting
	fmt.Println(count)

	// End of code
}

