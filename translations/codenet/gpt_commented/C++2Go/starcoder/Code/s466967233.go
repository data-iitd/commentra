package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function to read input from stdin
func readInput(reader *bufio.Reader) (N int, K int, A []int) {
	// Read the first line of input
	line, _ := reader.ReadString('\n')
	line = strings.TrimSpace(line)
	N, _ = strconv.Atoi(line)

	// Read the second line of input
	line, _ = reader.ReadString('\n')
	line = strings.TrimSpace(line)
	K, _ = strconv.Atoi(line)

	// Read the third line of input
	line, _ = reader.ReadString('\n')
	line = strings.TrimSpace(line)
	A = make([]int, N)
	for i := 0; i < N; i++ {
		A[i], _ = strconv.Atoi(line)
		line, _ = reader.ReadString('\n')
	}
	return
}

// Function to print output to stdout
func printOutput(N int, K int, A []int, now int) {
	fmt.Printf("%d\n", now)
}

// Main function
func main() {
	// Read input from stdin
	reader := bufio.NewReader(os.Stdin)
	N, K, A := readInput(reader)

	// Initialize variables
	now := 1
	cnt := 0

	// Initialize array B to -1 to indicate unvisited positions
	B := make([]int, 200100)
	for i := 0; i < 200100; i++ {
		B[i] = -1
	}

	// Mark the starting position as visited at step 0
	B[1] = 0

	// Traverse the positions based on the values in A
	for j := 1; j <= K; j++ {
		now = A[now]

		// Check if the current position has been visited before
		if B[now] == -1 {
			B[now] = j
		} else {
			// If the position has been visited, calculate the cycle length
			cnt = j
			break
		}
	}

	// If we did not reach the maximum steps K
	if j < K {
		// Calculate how many additional steps to take within the cycle
		tmp := (K - B[now]) % (cnt - B[now])

		// Move to the final position after the calculated additional steps
		for j := 0; j < tmp; j++ {
			now = A[now]
		}
	}

	// Output the final position after all movements
	printOutput(N, K, A, now)
}

