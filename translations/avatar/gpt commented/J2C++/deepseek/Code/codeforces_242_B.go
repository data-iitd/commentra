package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

func main() {
	// Create a Scanner object for input
	scanner := bufio.NewScanner(os.Stdin)
	
	// Read the number of pairs
	var n int
	scanner.Scan()
	fmt.Sscan(scanner.Text(), &n)
	
	// Initialize two slices to store the pairs
	a := make([]int, n)
	b := make([]int, n)
	
	// Initialize left to infinity and right to zero
	const INF = int(1e9) + 5
	left, right := INF, 0
	
	// Read the pairs and determine the minimum and maximum values
	for i := 0; i < n; i++ {
		scanner.Scan()
		fmt.Sscan(scanner.Text(), &a[i], &b[i])
		
		// Update left to the minimum value found in a
		if a[i] < left {
			left = a[i]
		}
		// Update right to the maximum value found in b
		if b[i] > right {
			right = b[i]
		}
	}
	
	// Check for a pair that matches the left and right bounds
	for i := 0; i < n; i++ {
		// If the current pair matches the min and max values
		if a[i] == left && b[i] == right {
			// Print the index (1-based) and exit
			fmt.Println(i + 1)
			return
		}
	}
	
	// If no matching pair is found, print -1
	fmt.Println(-1)
}

