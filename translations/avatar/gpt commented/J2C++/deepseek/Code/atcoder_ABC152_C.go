package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	// Call the solve method and print the result
	fmt.Println(solve())
}

func solve() int {
	// Create a Scanner object to read input from the user
	scanner := bufio.NewScanner(os.Stdin)
	
	// Read the number of elements in the array
	scanner.Scan()
	N, _ := strconv.Atoi(scanner.Text())
	
	// Initialize an array to hold the input values
	arr := make([]int, N)
	
	// Populate the array with user input
	for i := 0; i < N; i++ {
		scanner.Scan()
		arr[i], _ = strconv.Atoi(scanner.Text())
	}
	
	// Initialize a variable to keep track of the count of elements
	sum := 0
	
	// Create a slice to hold the elements
	var q []int
	
	// Iterate through the array to process each element
	for i := 0; i < len(arr); i++ {
		// Add the current element to the slice
		q = append(q, arr[i])
		
		// Sort the slice to maintain the order
		sort.Ints(q)
		
		// Check if the current element is less than or equal to the smallest element in the slice
		if arr[i] <= q[0] {
			// Increment the count if the condition is met
			sum++
		}
	}
	
	// Return the final count of elements that met the condition
	return sum
}
