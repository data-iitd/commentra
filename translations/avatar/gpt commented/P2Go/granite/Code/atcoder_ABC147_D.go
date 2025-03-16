
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const MOD = 1000000007

func main() {
	reader := bufio.NewReader(os.Stdin)

	// Read the number of elements in the array
	N, _ := strconv.Atoi(read(reader))

	// Read the input values and create a slice of integers
	A := make([]int, N)
	for i := 0; i < N; i++ {
		A[i], _ = strconv.Atoi(read(reader))
	}

	// Initialize the result variable to store the final answer
	result := 0

	// Iterate over each bit position from 0 to 59 (assuming 60 bits for integers)
	for b := 0; b < 60; b++ {
		// Count how many numbers have the b-th bit set (1)
		bs := 0
		for _, a := range A {
			if a&(1<<uint(b))!= 0 {
				bs++
			}
		}

		// Calculate the contribution of the b-th bit to the result
		// bs * (N - bs) gives the number of pairs with different b-th bits
		// (1 << b) gives the value of the b-th bit
		result = (result + bs*(N-bs)*(1<<uint(b))) % MOD
	}

	// Print the final result
	fmt.Println(result)
}

func read(reader *bufio.Reader) string {
	s, _ := reader.ReadString('\n')
	s = s[:len(s)-1]
	return s
}

