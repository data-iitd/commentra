package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function to calculate the number of combinations of elements having the same remainder
func combinations(A []int, M int) int {
	// Initialize a map to store the number of occurrences of each cumulative remainder
	remainder_counts := make(map[int]int)

	// Calculate cumulative remainders by performing modulo M operation on the sum of previous remainders and current element
	cum_remainders := make([]int, len(A)+1)
	cum_remainders[0] = 0
	for i := 0; i < len(A); i++ {
		cum_remainders[i+1] = (cum_remainders[i] + A[i]) % M
	}

	// Count the occurrences of each cumulative remainder
	for i := 0; i < len(cum_remainders); i++ {
		remainder_counts[cum_remainders[i]]++
	}

	// Calculate the number of combinations of elements having the same remainder
	combinations := 0
	for _, count := range remainder_counts {
		combinations += count * (count - 1) / 2
	}

	return combinations
}

func main() {
	// Read input number of rows and columns
	reader := bufio.NewReaderSize(os.Stdin, 1024 * 1024)
	fmt.Fscan(reader, &N, &M)

	// Initialize array 'A' with given dimensions
	A := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Fscan(reader, &A[i])
	}

	// Print the result
	fmt.Println(combinations(A, M))
}

