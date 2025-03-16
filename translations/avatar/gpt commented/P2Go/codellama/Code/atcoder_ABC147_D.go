
package main

import (
	"fmt"
	"math"
	"strconv"
	"strings"
)

func main() {
	// Read the number of elements in the array
	var N int
	fmt.Scan(&N)

	// Read the input values and create a slice of integers
	A := make([]int, N)
	for i := 0; i < N; i++ {
		A[i], _ = strconv.Atoi(strings.Split(fmt.Scanln(), " ")[0])
	}

	// Initialize the result variable to store the final answer
	result := 0

	// Iterate over each bit position from 0 to 59 (assuming 60 bits for integers)
	for b := 0; b < 60; b++ {
		// Count how many numbers have the b-th bit set (1)
		bs := 0
		for i := 0; i < N; i++ {
			if A[i]&(1<<b) > 0 {
				bs++
			}
		}

		// Calculate the contribution of the b-th bit to the result
		// bs * (N - bs) gives the number of pairs with different b-th bits
		// (1 << b) gives the value of the b-th bit
		result = (result + bs*(N-bs)*(1<<b)) % int(math.Pow(10, 9)+7)
	}

	// Print the final result
	fmt.Println(result)
}

