package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Create a Scanner object to read input from the console
	in := bufio.NewScanner(os.Stdin)
	in.Split(bufio.ScanWords)
	
	// Read the number of elements (N) and the values for L, R, QL, QR
	var N int
	var L, R, QL, QR int
	
	// Read N
	in.Scan()
	N = parseInt(in.Text())
	
	// Read L, R, QL, QR
	in.Scan()
	L = parseInt(in.Text())
	in.Scan()
	R = parseInt(in.Text())
	in.Scan()
	QL = parseInt(in.Text())
	in.Scan()
	QR = parseInt(in.Text())
	
	// Initialize an array to hold the weights and a prefix sum array
	W := make([]int, N) // Array to store weights
	sum := make([]int, N+1) // Prefix sum array
	
	// Read weights and compute the prefix sum
	for n := 0; n < N; n++ {
		in.Scan()
		W[n] = parseInt(in.Text()) // Read weight for each element
		sum[n+1] = sum[n] + W[n] // Update prefix sum
	}
	
	// Initialize a variable to track the minimum cost
	min := int(^uint(0) >> 1) // Start with the maximum possible value
	
	// Iterate over possible counts of elements assigned to the left side
	for firstR := 0; firstR <= N; firstR++ {
		lCount := firstR // Count of elements on the left
		rCount := N - lCount // Count of elements on the right
		
		// Calculate the candidate cost based on current left and right counts
		cand := int64(sum[lCount]) * int64(L) + int64(sum[N]-sum[lCount])*int64(R)
		
		// Calculate excess counts for left and right
		llCount := max(0, lCount - rCount - 1) // Excess left count
		rrCount := max(0, rCount - lCount - 1) // Excess right count
		
		// Add additional costs for excess elements
		cand += int64(llCount) * int64(QL) // Add cost for excess left elements
		cand += int64(rrCount) * int64(QR) // Add cost for excess right elements
		
		// Update the minimum cost found
		if cand < int64(min) {
			min = cand
		}
	}
	
	// Output the minimum cost
	fmt.Println(min) // Print the result
}

// Helper function to parse string to int
func parseInt(s string) int {
	var result int
	for _, c := range s {
		result = result*10 + int(c-'0')
	}
	return result
}

// Helper function to get the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

