
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Declare variables for the number of elements (N) and the threshold value (X)
	var N, X int

	// Read the values of N and X from standard input
	reader := bufio.NewReader(os.Stdin)
	N64, _ := reader.ReadString('\n')
	X64, _ := reader.ReadString('\n')
	N, _ = strconv.Atoi(N64)
	X, _ = strconv.Atoi(X64)

	// Initialize a slice L of size N to store the elements
	L := make([]int, N)

	// Read N elements into the slice L
	for i := 0; i < N; i++ {
		L[i], _ = strconv.Atoi(reader.ReadString('\n')[0 : len(reader.ReadString('\n')[0])-1])
	}

	// Initialize index variable and a variable to accumulate the sum
	i := 0
	d := 0

	// Iterate through the elements of the slice L
	for i = 0; i < N; i++ {
		// Accumulate the sum of elements
		d = d + L[i]

		// Check if the accumulated sum exceeds the threshold X
		if d > X {
			break // Exit the loop if the sum exceeds X
		}
	}

	// Output the number of elements processed before exceeding X
	fmt.Println(i + 1) // i + 1 because we want to count the number of elements
}

