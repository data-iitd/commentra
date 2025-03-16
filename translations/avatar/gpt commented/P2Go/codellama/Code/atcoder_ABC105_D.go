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
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	tokens := strings.Fields(line)
	N, _ := strconv.Atoi(tokens[0])
	M, _ := strconv.Atoi(tokens[1])

	// Read the array A from standard input and convert it to a slice of int64 type
	A := make([]int64, N)
	line, _ = reader.ReadString('\n')
	tokens = strings.Fields(line)
	for i := 0; i < N; i++ {
		A[i], _ = strconv.ParseInt(tokens[i], 10, 64)
	}

	// Calculate cumulative remainders of the array A when divided by M
	// Start with a 0 to handle the case of subarrays starting from index 0
	cum_remainders := make([]int64, N+1)
	cum_remainders[0] = 0
	for i := 1; i <= N; i++ {
		cum_remainders[i] = (cum_remainders[i-1] + A[i-1]) % int64(M)
	}

	// Count the occurrences of each remainder using a map
	remainder_counts := make(map[int64]int)
	for _, remainder := range cum_remainders {
		remainder_counts[remainder]++
	}

	// Initialize a variable to count the number of valid combinations
	combinations := 0

	// Calculate the number of combinations of indices that have the same remainder
	for _, count := range remainder_counts {
		combinations += count * (count - 1) / 2 // Combinations of 2 from count
	}

	// Output the total number of combinations found
	fmt.Println(combinations)
}

