package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	
	// Read input values: n (number of elements) and x (a multiplier)
	input, _ := reader.ReadString('\n')
	parts := strings.Split(strings.TrimSpace(input), " ")
	n, _ := strconv.Atoi(parts[0])
	x, _ := strconv.Atoi(parts[1])
	
	// Read the list of integers 'a' from input
	input, _ = reader.ReadString('\n')
	parts = strings.Split(strings.TrimSpace(input), " ")
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(parts[i])
	}
	
	// Initialize a 2D slice 'b' with nil values to store minimum values
	b := make([][]int, n)
	for i := range b {
		b[i] = make([]int, n)
		for j := range b[i] {
			b[i][j] = -1 // Use -1 to indicate uninitialized
		}
	}
	
	// Fill the 2D slice 'b' with minimum values from 'a'
	for i := 0; i < n; i++ {
		m := a[i]  // Start with the current element
		for j := 0; j < n; j++ {
			k := i - j  // Calculate the index to wrap around
			if k < 0 {
				k += n  // Wrap around if index is negative
			}
			m = min(m, a[k])  // Update m to be the minimum value found
			b[j][i] = m  // Store the minimum value in the 2D slice 'b'
		}
	}
	
	// Initialize a large value for comparison
	m := 1000000000000000
	
	// Calculate the minimum sum of elements in each row of 'b' plus the weighted index
	for i := range b {
		sum := 0
		for j := range b[i] {
			sum += b[i][j]
		}
		if sum + x * i < m {
			m = sum + x * i
		}
	}
	
	// Print the final minimum value
	fmt.Println(m)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
