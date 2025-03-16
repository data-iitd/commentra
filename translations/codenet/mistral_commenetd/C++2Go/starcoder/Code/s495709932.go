
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"math"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	// Read the number of elements in the vector
	N, _ := strconv.Atoi(os.Args[1])

	// Initialize a vector of size N with integers
	A := make([]int, N)
	for i := 0; i < N; i++ {
		A[i], _ = strconv.Atoi(os.Args[2+i])
	}

	// Initialize the answer variable to 0
	answer := 0

	// Outer loop iterates through each element in the vector except the last one
	for i := 0; i < N-1; i++ {
		// Inner loop iterates through the remaining elements in the vector starting from the next element
		for j := i + 1; j < N; j++ {
			// Calculate the absolute difference between the current and next elements
			diff := int(math.Abs(float64(A[i] - A[j])))

			// Update the answer variable with the maximum difference found so far
			answer = int(math.Max(float64(answer), float64(diff)))
		}
	}

	// Print the answer
	fmt.Println(answer)
}

