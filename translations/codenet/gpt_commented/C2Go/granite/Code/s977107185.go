
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Declare variables
	var i, j, N, A int
	var tmp int
	var count int = 0
	var A_array []int

	// Read the number of elements to be sorted
	fmt.Fscanf(bufio.NewReader(os.Stdin), "%d\n", &N)

	// Input the elements into the array A
	for i = 0; i < N; i++ {
		fmt.Fscanf(bufio.NewReader(os.Stdin), "%d\n", &A)
		A_array = append(A_array, A)
	}

	// Perform bubble sort on the array A
	for i = 0; i < N - 1; i++ {
		for j = N - 1; j > i; j-- {
			// Compare adjacent elements and swap if they are in the wrong order
			if A_array[j] < A_array[j - 1] {
				tmp = A_array[j]
				A_array[j] = A_array[j - 1]
				A_array[j - 1] = tmp

				// Increment the swap count
				count++
			}
		}
	}

	// Output the sorted array
	for i = 0; i < N; i++ {
		fmt.Printf("%d", A_array[i])

		// Print a space between elements, but not after the last element
		if i < N - 1 {
			fmt.Print(" ")
		}
	}

	// Print a newline after the sorted array
	fmt.Println()

	// Print the total number of swaps made during sorting
	fmt.Println(count)
}

