

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Declare variables
	var n, i, j, q, sum int
	var x, y []int

	// Read the number of elements in the array x
	fmt.Fscanf(bufio.NewReader(os.Stdin), "%d\n", &n)

	// Allocate memory for array x
	x = make([]int, n)
	for i = 0; i < n; i++ {
		// Read each element of array x
		fmt.Fscanf(bufio.NewReader(os.Stdin), "%d\n", &x[i])
	}

	// Read the number of queries
	fmt.Fscanf(bufio.NewReader(os.Stdin), "%d\n", &q)

	// Allocate memory for array y
	y = make([]int, q)
	for i = 0; i < q; i++ {
		// Read each element of array y
		fmt.Fscanf(bufio.NewReader(os.Stdin), "%d\n", &y[i])
	}

	// Initialize sum to zero
	sum = 0

	// Check if each element of array y is present in array x and increment sum if found
	for i = 0; i < q; i++ {
		for j = 0; j < n; j++ {
			// Check if current element of y is equal to current element of x
			if y[i] == x[j] {
				// Increment sum if found
				sum = sum + 1
				// Break out of inner loop as soon as a match is found
				break
			}
		}
	}

	// Print the value of sum
	fmt.Println(sum)
}

