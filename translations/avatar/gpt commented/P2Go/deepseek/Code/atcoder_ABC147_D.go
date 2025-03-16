package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	// Read the number of elements in the array
	line, _ := reader.ReadString('\n')
	N, _ := strconv.Atoi(strings.TrimSpace(line))

	// Read the input values and create a NumPy array of integers
	line, _ = reader.ReadString('\n')
	parts := strings.Fields(strings.TrimSpace(line))
	A := make([]int64, N)
	for i := 0; i < N; i++ {
		A[i], _ = strconv.ParseInt(parts[i], 10, 64)
	}

	// Initialize the result variable to store the final answer
	var result int64 = 0

	// Iterate over each bit position from 0 to 59 (assuming 60 bits for integers)
	for b := 0; b < 60; b++ {
		// Count how many numbers have the b-th bit set (1)
		var bs int64 = 0
		for _, num := range A {
			if (num>>int64(b))&1 == 1 {
				bs++
			}
		}

		// Calculate the contribution of the b-th bit to the result
		// bs * (N - bs) gives the number of pairs with different b-th bits
		// (1 << b) gives the value of the b-th bit
		result = (result + bs*(N-bs)*(1<<b)) % 1000000007
	}

	// Print the final result
	fmt.Println(result)
}
