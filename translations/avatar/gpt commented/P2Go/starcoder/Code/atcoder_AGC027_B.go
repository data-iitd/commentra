package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read input values from stdin
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	N, _ := strconv.Atoi(strings.TrimSpace(line))
	line, _ = reader.ReadString('\n')
	X, _ := strconv.Atoi(strings.TrimSpace(line))
	A := make([]int, N)
	for i := 0; i < N; i++ {
		line, _ = reader.ReadString('\n')
		A[i], _ = strconv.Atoi(strings.TrimSpace(line))
	}

	// Calculate the cumulative sum of the list A
	S := make([]int, N)
	for i := 0; i < N; i++ {
		if i == 0 {
			S[i] = A[i]
		} else {
			S[i] = S[i-1] + A[i]
		}
	}

	// Initialize the answer to a very large number (infinity)
	ans := int(1e9)

	// Iterate through the cumulative sums with an index starting from 1
	for k := 1; k < N; k++ {
		// Calculate the expression E based on the current index k and the cumulative sums
		E := k * X + 2 * sum(S[j] for j := N - 2 * k - 1; j >= 0; j -= k)

		// Update the answer with the minimum value found so far
		ans = min(ans, E)
	}

	// Print the final result, which includes the minimum value found, adjusted by N * X and 5 times the last cumulative sum
	fmt.Println(ans + N * X + 5 * S[N-1])
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func sum(s []int) int {
	var sum int
	for _, v := range s {
		sum += v
	}
	return sum
}

