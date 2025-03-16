package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Create a Scanner object to read input from the console
	scanner := bufio.NewScanner(os.Stdin)
	
	// Read the number of pairs of integers to be processed
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	
	// Initialize an array to store the characters representing the actions
	ch := make([]byte, n)
	
	// Initialize sums for two different actions
	s1, s2 := 0, 0
	
	// Process each pair of integers
	for i := 0; i < n; i++ {
		// Read the next pair of integers
		scanner.Scan()
		x, _ := strconv.Atoi(scanner.Text())
		scanner.Scan()
		y, _ := strconv.Atoi(scanner.Text())
		
		// Calculate temporary sums for the current iteration
		temp1 := s1 + x
		temp2 := s2 + y
		
		// Check if adding x to s1 keeps the difference within 500
		if abs(temp1 - s2) <= 500 {
			s1 += x // Update s1
			ch[i] = 'A' // Record the action 'A'
			continue // Move to the next iteration
		}
		
		// Check if adding y to s2 keeps the difference within 500
		if abs(temp2 - s1) <= 500 {
			s2 += y // Update s2
			ch[i] = 'G' // Record the action 'G'
			continue // Move to the next iteration
		}
		
		// If neither condition is met, set flag to indicate failure
		fmt.Println(-1) // Output -1 to indicate failure
		return // Exit the program
	}
	
	// Output the recorded actions
	fmt.Println(string(ch))
}

// Helper function to calculate the absolute value
func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

