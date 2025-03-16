
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

func main() {
	// Read the number of elements
	N, _ := strconv.Atoi(bufio.NewReader(os.Stdin).ReadLine()[0:1])

	// Initialize two slices to store the input values
	X := make([]int, N)
	Y := make([]int, N)

	// Read input values into slice X and copy them to slice Y
	for i := 0; i < N; i++ {
		X[i], _ = strconv.Atoi(bufio.NewReader(os.Stdin).ReadLine()[0:1])
		Y[i] = X[i]
	}

	// Sort slice Y to find the median
	sort.Ints(Y)

	// Find the median value (middle element for odd N, or lower middle for even N)
	y := Y[N/2]

	// Output the appropriate median value for each element in X
	for i := 0; i < N; i++ {
		// If the current element in X is less than the median
		if X[i] < Y[N/2] {
			fmt.Println(Y[N/2]) // Output the upper median
		} else {
			fmt.Println(Y[N/2-1]) // Output the lower median
		}
	}
}

