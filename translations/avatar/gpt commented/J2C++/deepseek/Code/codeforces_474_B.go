package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Create a Scanner object to read input from the console
	scanner := bufio.NewScanner(os.Stdin)
	
	// Read the number of elements in the array
	scanner.Scan()
	n, _ := fmt.Sscan(scanner.Text(), &n)
	
	// Initialize the array to store cumulative sums
	arr := make([]int, n)
	
	// Read the first element and assign it to the first index of the array
	scanner.Scan()
	arr[0], _ = fmt.Sscan(scanner.Text(), &arr[0])
	
	// Populate the array with cumulative sums
	for i := 1; i < n; i++ {
		// Read the next integer and add it to the previous cumulative sum
		scanner.Scan()
		var x int
		fmt.Sscan(scanner.Text(), &x)
		arr[i] = x + arr[i - 1]
	}
	
	// Read the number of queries
	scanner.Scan()
	m, _ := fmt.Sscan(scanner.Text(), &m)
	
	// Initialize the array to store the queries
	q := make([]int, m)
	
	// Read each query into the array
	for i := 0; i < m; i++ {
		scanner.Scan()
		fmt.Sscan(scanner.Text(), &q[i])
	}
	
	// Process each query and print the result
	for k := 0; k < m; k++ {
		fmt.Println(fun(arr, q[k], n, m) + 1)
	}
}

// Function to perform binary search on the cumulative sum array
func fun(arr []int, q int, n int, m int) int {
	res := 0 // Variable to store the result index
	i, j := 0, n // Initialize pointers for binary search
	
	// Perform binary search to find the appropriate index
	for i <= j {
		md := i + (j - i) / 2
		
		// If the middle element is equal to the query, return the index
		if arr[md] == q {
			return md
		} else if arr[md] > q { // If the middle element is greater than the query, adjust the search range
			res = md // Update result to the current mid index
			j = md - 1 // Move the end pointer left
		} else {
			i = md + 1 // Move the start pointer right
		}
	}
	
	// Return the last found index where the cumulative sum is less than the query
	return res
}

