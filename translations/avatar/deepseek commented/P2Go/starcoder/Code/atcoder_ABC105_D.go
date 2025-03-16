package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the values of N and M from the standard input
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	N, _ := strconv.Atoi(strings.TrimSpace(line))
	line, _ = reader.ReadString('\n')
	M, _ := strconv.Atoi(strings.TrimSpace(line))

	// Read the array A from the standard input
	A := make([]int, N)
	for i := 0; i < N; i++ {
		line, _ := reader.ReadString('\n')
		A[i], _ = strconv.Atoi(strings.TrimSpace(line))
	}

	// Calculate the cumulative remainders of the array A modulo M
	// Include a 0 at the beginning to handle the case when the cumulative sum starts from 0
	cum_remainders := make([]int, N+1)
	cum_remainders[0] = 0
	for i := 0; i < N; i++ {
		cum_remainders[i+1] = (cum_remainders[i] + A[i]) % M
	}

	// Count the occurrences of each remainder
	remainder_counts := make(map[int]int)
	for _, remainder := range cum_remainders {
		remainder_counts[remainder]++
	}

	// Initialize the number of combinations
	combinations := 0

	// Calculate the number of combinations where the difference between two remainders is a multiple of M
	for count := range remainder_counts {
		combinations += count * (count - 1) / 2
	}

	// Print the number of combinations
	fmt.Println(int(combinations))
}

