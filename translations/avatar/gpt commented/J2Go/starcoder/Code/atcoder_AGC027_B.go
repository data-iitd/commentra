package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read input from stdin
	reader := bufio.NewReader(os.Stdin)
	// Read the number of elements N and the multiplier X
	line, _ := reader.ReadString('\n')
	N, _ := strconv.Atoi(strings.TrimSpace(line))
	line, _ = reader.ReadString('\n')
	X, _ := strconv.ParseInt(strings.TrimSpace(line), 10, 64)
	// Initialize an array to store the elements and a prefix sum array
	x := make([]int, N)
	xsum := make([]int, N + 1)
	// Read the elements into the array and compute the prefix sums
	for i := 0; i < N; i++ {
		line, _ := reader.ReadString('\n')
		x[i], _ = strconv.Atoi(strings.TrimSpace(line))
		xsum[i + 1] = xsum[i] + x[i]
	}
	// Initialize the answer with the cost of processing all elements with the base cost
	ans := X * N + 5 * xsum[N]
	// Iterate through possible splits of the array
	for i := 1; i < N; i++ {
		// Calculate the cost for the current split
		cost := X * i + 5 * (xsum[N] - xsum[N - i])
		// Incrementally add costs based on the current split
		for j := 5; j <= 100; j += 2 {
			// If the current cost exceeds the best answer found, break out of the loop
			if cost > ans {
				break
			}
			// Update the cost based on the prefix sums
			for k := N - i; k >= 0; k -= i {
				cost += j * (xsum[k] - xsum[max(k-i, 0)])
			}
		}
		// Update the answer with the minimum cost found
		ans = min(ans, cost)
	}
	// Output the final answer, which includes the base cost
	fmt.Println(ans + N * X)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

