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

func main() {
	// Read the size of the arrays
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter the size of the arrays: ")
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)
	N, _ := strconv.Atoi(input)

	// Declare arrays A and B with sizes N+1 and N respectively
	A := make([]int, N+1)
	B := make([]int, N)
	var i int

	// Read N+1 integers into array A
	fmt.Print("Enter the elements of the array A: ")
	for i = 0; i < N+1; i++ {
		input, _ = reader.ReadString('\n')
		input = strings.TrimSpace(input)
		A[i], _ = strconv.Atoi(input)
	}

	// Read N integers into array B
	fmt.Print("Enter the elements of the array B: ")
	for i = 0; i < N; i++ {
		input, _ = reader.ReadString('\n')
		input = strings.TrimSpace(input)
		B[i], _ = strconv.Atoi(input)
	}

	// Initialize the result variable
	var ans int64 = 0

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
	fmt.Printf("The maximum possible sum is %d\n", ans)
}

