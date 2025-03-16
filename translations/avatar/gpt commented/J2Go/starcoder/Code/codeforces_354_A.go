package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a buffered reader to read input from the console
	reader := bufio.NewReader(os.Stdin)
	
	// Read the number of elements (N) and the values for L, R, QL, QR
	N, L, R, QL, QR := readInput(reader)
	
	// Initialize an array to hold the weights and a prefix sum array
	W := make([]int, N) // Array to store weights
	sum := make([]int, N + 1) // Prefix sum array
	
	// Read weights and compute the prefix sum
	for n := 0; n < N; n++ {
		W[n], _ = strconv.Atoi(readLine(reader)) // Read weight for each element
		sum[n + 1] = sum[n] + W[n] // Update prefix sum
	}
	
	// Initialize a variable to track the minimum cost
	min := int64(1e18) // Start with the maximum possible value
	
	// Iterate over possible counts of elements assigned to the left side
	for firstR := 0; firstR <= N; firstR++ {
		lCount := firstR // Count of elements on the left
		rCount := N - lCount // Count of elements on the right
		
		// Calculate the candidate cost based on current left and right counts
		cand := int64(sum[lCount] * L + (sum[N] - sum[lCount]) * R)
		
		// Calculate excess counts for left and right
		llCount := int(max(0, float64(lCount - rCount - 1))) // Excess left count
		rrCount := int(max(0, float64(rCount - lCount - 1))) // Excess right count
		
		// Add additional costs for excess elements
		cand += int64(llCount * QL) // Add cost for excess left elements
		cand += int64(rrCount * QR) // Add cost for excess right elements
		
		// Update the minimum cost found
		min = min(min, cand) // Keep track of the minimum cost
	}
	
	// Output the minimum cost
	fmt.Println(min) // Print the result
}

// Utility functions
func readInput(reader *bufio.Reader) (int, int, int, int, int) {
	// Read the number of elements (N) and the values for L, R, QL, QR
	line, _ := reader.ReadString('\n')
	line = strings.TrimSpace(line)
	N, _ := strconv.Atoi(line)
	line, _ = reader.ReadString('\n')
	line = strings.TrimSpace(line)
	L, _ := strconv.Atoi(line)
	line, _ = reader.ReadString('\n')
	line = strings.TrimSpace(line)
	R, _ := strconv.Atoi(line)
	line, _ = reader.ReadString('\n')
	line = strings.TrimSpace(line)
	QL, _ := strconv.Atoi(line)
	line, _ = reader.ReadString('\n')
	line = strings.TrimSpace(line)
	QR, _ := strconv.Atoi(line)
	return N, L, R, QL, QR
}

func readLine(reader *bufio.Reader) string {
	// Read a line of input from the console
	line, _ := reader.ReadString('\n')
	line = strings.TrimSpace(line)
	return line
}

func min(a, b int64) int64 {
	// Return the minimum of two values
	if a < b {
		return a
	}
	return b
}

func max(a, b float64) float64 {
	// Return the maximum of two values
	if a > b {
		return a
	}
	return b
}

