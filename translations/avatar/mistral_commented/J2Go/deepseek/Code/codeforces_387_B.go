package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Initialize Scanner to read input from the standard input
	scanner := bufio.NewScanner(os.Stdin)

	// Read the number of requests and preemptions from the input
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	m, _ := strconv.Atoi(scanner.Text())

	// Create slices to store request and preemption indices
	req := make([]int, n)
	pre := make([]int, m)

	// Read request indices and store them in the slice
	for i := 0; i < n; i++ {
		scanner.Scan()
		req[i], _ = strconv.Atoi(scanner.Text())
		// Comment: Read and store request index i
	}

	// Read preemption indices and store them in the slice
	for i := 0; i < m; i++ {
		scanner.Scan()
		pre[i], _ = strconv.Atoi(scanner.Text())
		// Comment: Read and store preemption index i
	}

	// Initialize index variables for requests and preemptions
	i := n - 1
	j := m - 1

	// Initialize answer variable
	ans := 0

	// While there are still requests and preemptions to compare
	for i >= 0 && j >= 0 {
		// If the current request can preempt the current preemption
		if req[i] > pre[j] {
			// Increment answer variable
			ans++
		} else {
			// Decrement preemption index
			j--
		}
		// Decrement request index
		i--
	}

	// Print the answer and the number of remaining requests
	fmt.Println(ans + i + 1)
}
