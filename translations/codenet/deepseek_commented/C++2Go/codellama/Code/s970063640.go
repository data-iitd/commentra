package main

import (
	"fmt"
	"sort"
)

func main() {
	var n int // Declare an integer variable to store the number of elements
	fmt.Scan(&n) // Read the value of n from the standard input
	var a int // Declare an integer variable to store the value of a
	fmt.Scan(&a) // Read the value of a from the standard input
	var sum int = 0 // Initialize a variable to store the sum of the last 'a' elements
	s := make([]int, n) // Declare an array to store the elements
	for i := 0; i < n; i++ { // Loop to read 'n' elements into the array 's'
		fmt.Scan(&s[i]) // Read the elements from the standard input
	}
	sort.Ints(s) // Sort the array 's' in ascending order
	for i := n - 1; i > n-a-1; i-- { // Loop to calculate the sum of the last 'a' elements
		sum += s[i] // Add the value of the current element to the sum
	}
	fmt.Println(sum) // Print the calculated sum to the standard output
}

