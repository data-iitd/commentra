

package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	// Read the number of elements in the vector
	NTemp, err := reader.ReadString('\n')
	checkError(err)
	N, err := strconv.ParseInt(strings.TrimSpace(NTemp), 10, 64)
	checkError(err)

	// Initialize a vector of size N with integers
	A := make([]int64, N)
	for i := int64(0); i < N; i++ {
		// Read the value of the current element in the vector
		ATemp, err := reader.ReadString('\n')
		checkError(err)
		A[i], err = strconv.ParseInt(strings.TrimSpace(ATemp), 10, 64)
		checkError(err)
	}

	// Initialize the answer variable to 0
	answer := int64(0)

	// Outer loop iterates through each element in the vector except the last one
	for i := int64(0); i < N-1; i++ {
		// Inner loop iterates through the remaining elements in the vector starting from the next element
		for j := i + 1; j < N; j++ {
			// Calculate the absolute difference between the current and next elements
			diff := int64(abs(int(A[i]), int(A[j])))

			// Update the answer variable with the maximum difference found so far
			if diff > answer {
				answer = diff
			}
		}
	}

	// Print the answer
	fmt.Println(answer)
}

func abs(x, y int) int {
	if x < y {
		return y - x
	}
	return x - y
}

func checkError(err error) {
	if err!= nil {
		panic(err)
	}
}

