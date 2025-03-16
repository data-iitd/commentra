package main

import (
	"fmt"
)

func main() {
	// Declare variables to store the input values
	var n, k, q int
	
	// Read three integers from the standard input
	fmt.Scan(&n, &k, &q)
	
	// Declare an array of size n initialized to 0
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		arr[i] = 0 // Initialize each element to 0
	}
	
	// Read q integers and increment the corresponding index in the array arr
	for i := 0; i < q; i++ {
		var temp int
		fmt.Scan(&temp)
		arr[temp-1] += 1
	}
	
	// Check if the value at each index in arr is greater than q-k
	for i := 0; i < n; i++ {
		if arr[i] > (q - k) {
			fmt.Println("Yes") // Print "Yes" if the condition is met
		} else {
			fmt.Println("No") // Print "No" otherwise
		}
	}
}

