
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Read the size of the arrays
	N, _ := strconv.Atoi(bufio.NewReader(os.Stdin).ReadLine()[0:1])

	// Declare arrays A and B with sizes N+1 and N respectively
	A := make([]int, N+1)
	B := make([]int, N)
	var i int

	// Read N+1 integers into array A
	for i = 0; i < N+1; i++ {
		A[i], _ = strconv.Atoi(bufio.NewReader(os.Stdin).ReadLine()[0:1])
	}

	// Read N integers into array B
	for i = 0; i < N; i++ {
		B[i], _ = strconv.Atoi(bufio.NewReader(os.Stdin).ReadLine()[0:1])
	}

	// Initialize the result variable
	ans := int64(0)

	// Loop through each index from 0 to N-1
	for i = 0; i < N; i++ {

		// Site i
		// Check if the current element in A is greater than or equal to the current element in B
		if A[i] >= B[i] {
			// Add the current element in B to ans and subtract it from A
			ans = ans + int64(B[i])
			A[i] = A[i] - B[i]
			// Set the current element in B to 0
			B[i] = 0
		} else {
			// Add the current element in A to ans and subtract it from B
			ans = ans + int64(A[i])
			B[i] = B[i] - A[i]
			// Set the current element in A to 0
			A[i] = 0
		}

		// Site i + 1
		// Check if the next element in A is greater than or equal to the current element in B
		if A[i+1] >= B[i] {
			// Add the current element in B to ans and subtract it from A
			ans = ans + int64(B[i])
			A[i+1] = A[i+1] - B[i]
			// Set the current element in B to 0
			B[i] = 0
		} else {
			// Add the current element in A to ans and subtract it from B
			ans = ans + int64(A[i+1])
			B[i] = B[i] - A[i+1]
			// Set the current element in A to 0
			A[i+1] = 0
		}
	}

	// Print the final result
	fmt.Println(ans)
}
