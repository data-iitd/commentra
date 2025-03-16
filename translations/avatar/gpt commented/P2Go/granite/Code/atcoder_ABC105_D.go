
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Read the values of N and M from standard input
	reader := bufio.NewReader(os.Stdin)
	line, _, _ := reader.ReadLine()
	N, M := parseLine(line)

	// Read the array A from standard input and convert it to a slice of int64 type
	line, _, _ = reader.ReadLine()
	A := parseLine(line)

	// Calculate cumulative remainders of the array A when divided by M
	// Start with a 0 to handle the case of subarrays starting from index 0
	cum_remainders := make([]int64, N+1)
	cum_remainders[0] = 0
	for i := 1; i <= N; i++ {
		cum_remainders[i] = (cum_remainders[i-1] + A[i-1]) % M
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
		combinations += count * (count - 1) / 2  // Combinations of 2 from count
	}

	// Output the total number of combinations found
	fmt.Println(combinations)
}

func parseLine(line []byte) []int64 {
	tokens := bytes.Split(line, []byte{' '})
	A := make([]int64, len(tokens))
	for i, token := range tokens {
		A[i], _ = strconv.ParseInt(string(token), 10, 64)
	}
	return A
}

