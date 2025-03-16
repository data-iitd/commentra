package main

import (
	"fmt"
)

func main() {
	// Read the input string from the user
	var soz string
	fmt.Scanln(&soz)

	// Initialize a slice 'a' to store the cumulative count of consecutive characters
	// The length of 'a' is one more than the length of 'soz' to handle the base case
	a := make([]int, len(soz)+1)

	// Iterate through the string to fill the cumulative count slice 'a'
	for i := 1; i < len(soz); i++ {
		// Carry forward the previous count
		a[i] = a[i-1]

		// If the current character is the same as the previous one, increment the count
		if soz[i-1] == soz[i] {
			a[i]++
		}
	}

	// Read the number of queries from the user
	var n int
	fmt.Scan(&n)

	// Initialize a slice to store the results of each query
	arr := make([]int, n)

	// Process each query
	for i := 0; i < n; i++ {
		var m, l int
		fmt.Scan(&m, &l)

		// Calculate the number of consecutive characters between indices m and l
		// and store the result in the 'arr' slice
		arr[i] = a[l-1] - a[m-1]
	}

	// Print the results for each query
	for _, result := range arr {
		fmt.Println(result)
	}
}

// <END-OF-CODE>
