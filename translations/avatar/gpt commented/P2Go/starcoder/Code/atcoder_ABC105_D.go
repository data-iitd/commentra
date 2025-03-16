package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the values of N and M from standard input
	reader := bufio.NewReaderSize(os.Stdin, 1024 * 1024)
	fmt.Fscan(reader, &N, &M)

	// Read the array A from standard input and convert it to a NumPy array of int64 type
	A := make([]int64, N)
	for i := 0; i < N; i++ {
		fmt.Fscan(reader, &A[i])
	}

	// Calculate cumulative remainders of the array A when divided by M
	// Start with a 0 to handle the case of subarrays starting from index 0
	cum_remainders := make([]int64, N + 1)
	cum_remainders[0] = 0
	for i := 0; i < N; i++ {
		cum_remainders[i + 1] = (cum_remainders[i] + A[i]) % M

	// Count the occurrences of each remainder using Counter
	remainder_counts := make(map[int64]int)
	for _, remainder := range cum_remainders {
		remainder_counts[remainder]++
	}

	// Initialize a variable to count the number of valid combinations
	combinations := 0

	// Calculate the number of combinations of indices that have the same remainder
	for count := range remainder_counts {
		combinations += count * (count - 1) / 2 // Combinations of 2 from count
	}

	// Output the total number of combinations found
	fmt.Println(combinations)
}

