package main

import (
	"fmt"
)

func main() {
	// Declare variables to store the input values
	var n, k, q int64

	// Read three long integers from the standard input
	fmt.Scan(&n, &k, &q)

	// Declare an array of size n initialized to 0
	arr := make([]int64, n+1) // Use n+1 to accommodate 1-based indexing

	// Read q integers and increment the corresponding index in the array arr
	for i := int64(0); i < q; i++ {
		var temp int64
		fmt.Scan(&temp)
		arr[temp] += 1
	}

	// Check if the value at each index in arr is greater than q-k
	for i := int64(1); i <= n; i++ {
		if arr[i] > (q - k) {
			fmt.Println("Yes") // Print "Yes" if the condition is met
		} else {
			fmt.Println("No") // Print "No" otherwise
		}
	}
}

// <END-OF-CODE>
