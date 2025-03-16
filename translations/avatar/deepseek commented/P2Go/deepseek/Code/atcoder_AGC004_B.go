package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	
	// Read the values of n and x
	var n, x int
	fmt.Fscan(reader, &n, &x)
	
	// Read the list of integers a
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &a[i])
	}
	
	// Initialize a 2D slice b with nil values
	// b[j][i] will store the minimum value in the circular array from i to j
	b := make([][]int, n)
	for i := 0; i < n; i++ {
		b[i] = make([]int, n)
		for j := 0; j < n; j++ {
			b[i][j] = -1 // Use -1 to indicate uninitialized
		}
	}
	
	// Calculate the minimum value in a circular array for each starting position i and ending position j
	for i := 0; i < n; i++ {
		m := a[i]  // Initialize m with the current element
		for j := 0; j < n; j++ {
			k := i - j  // Calculate the index in the circular array
			if k < 0 {
				k += n  // Adjust k if it is negative
			}
			if a[k] < m {
				m = a[k]  // Update m with the minimum value in the circular array
			}
			b[j][i] = m  // Store the minimum value in b
		}
	}
	
	// Find the minimum sum of each row in b plus x times the row index
	m := 1000000000000000 // Use a large number to represent infinity
	for i := 0; i < n; i++ {
		sum := 0
		for j := 0; j < n; j++ {
			sum += b[i][j]
		}
		if sum + x * i < m {
			m = sum + x * i
		}
	}
	
	// Print the minimum value found
	fmt.Println(m)
}
