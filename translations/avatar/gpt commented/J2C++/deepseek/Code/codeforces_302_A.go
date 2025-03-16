package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Create a Scanner object to read input from the console
	scanner := bufio.NewScanner(os.Stdin)
	
	// Read the number of elements in the array and the number of queries
	scanner.Scan()
	fmt.Sscan(scanner.Text(), &n, &k)
	
	// Initialize an array to hold the input values
	arr := make([]int, n)
	
	// Populate the array with input values
	for i := 0; i < n; i++ {
		scanner.Scan()
		fmt.Sscan(scanner.Text(), &arr[i])
	}
	
	// Counters for the number of 1s (o) and 0s (e) in the array
	var o, e int
	
	// Count the number of 1s and 0s in the array
	for i := 0; i < n; i++ {
		if arr[i] == 1 {
			o++
		} else {
			e++
		}
	}
	
	// Process each query
	for i := 0; i < k; i++ {
		// Read the left and right indices for the current query
		scanner.Scan()
		fmt.Sscan(scanner.Text(), &l, &r)
		
		// Check if the number of elements in the range is odd
		if (r - l + 1) % 2 == 1 {
			fmt.Println("0")
		} else {
			// If even, check if we can form a valid pair of 1s and 0s
			if (r - l + 1) / 2 <= o && (r - l + 1) / 2 <= e {
				fmt.Println("1")
			} else {
				fmt.Println("0")
			}
		}
	}
