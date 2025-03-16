
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Declare variables
var N int
var ans int
var i int
var count int

func main() {
	// Read the number of elements in the array from the user
	fmt.Scanf("%d", &N)

	// Declare and initialize an integer array A of size N
	A := make([]int, N)

	// Read elements of the array A from the user
	for i = 0; i < N; i++ {
		fmt.Scanf("%d", &A[i]) // Read the i-th element of array A
	}

	// Initialize variables i, ans, and count to 0
	i = 0
	ans = 0
	count = 0

	// Traverse the array using a while loop
	for i < N-1 {
<<<<<<< HEAD

=======
>>>>>>> 98c87cb78a (data updated)
		// Check if the current and next elements of the array are equal
		if A[i] == A[i+1] {
			// Increment the count if the current and next elements are equal
			count++

			// If the count is odd, increment the answer
			if count%2!= 0 {
				ans++
			}
		}
		// Reset the count to 0 if the current and next elements are not equal
		else {
			count = 0
		}

		// Increment the index i to move to the next element of the array
		i++
	}

	// Print the answer
	fmt.Printf("%d\n", ans)
}

