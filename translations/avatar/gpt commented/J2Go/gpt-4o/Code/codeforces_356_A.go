package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Initialize FastReader to read input efficiently
	reader := bufio.NewReader(os.Stdin)

	// Read the number of elements
	nStr, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(strings.TrimSpace(nStr))

	// Create a slice to keep track of available positions on the left
	left := make([]int, n)
	for i := 0; i < n; i++ {
		left[i] = i
	}

	// Initialize an array to store the answers
	answer := make([]int, n)

	// Read the number of queries
	qStr, _ := reader.ReadString('\n')
	q, _ := strconv.Atoi(strings.TrimSpace(qStr))

	// Process each query
	for i := 0; i < q; i++ {
		queryStr, _ := reader.ReadString('\n')
		query := strings.Fields(queryStr)
		l, _ := strconv.Atoi(query[0])
		r, _ := strconv.Atoi(query[1])
		win, _ := strconv.Atoi(query[2])

		// Adjust l and r to be zero-indexed
		l--
		r--

		// Update the answer array for all positions in the range [l, r]
		for j := l; j <= r; j++ {
			if left[j] != -1 {
				answer[left[j]] = win
				left[j] = -1 // Mark this position as used
			}
		}

		// Mark the winning index as available again
		answer[win-1] = 0
		left[win-1] = win - 1 // Add the winning index back to available positions
	}

	// Build the output string from the answer array
	var ans strings.Builder
	for i := 0; i < n; i++ {
		ans.WriteString(fmt.Sprintf("%d ", answer[i]))
	}

	// Print the final answer
	fmt.Println(strings.TrimSpace(ans.String()))
}

// <END-OF-CODE>
