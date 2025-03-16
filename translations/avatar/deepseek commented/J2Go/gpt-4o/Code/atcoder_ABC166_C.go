package main

import (
	"fmt"
)

func main() {
	var N int
	var M int64
	fmt.Scan(&N) // Read the number of elements N
	fmt.Scan(&M) // Read the number of comparisons M

	H := make([]int64, N) // Initialize a slice to store the heights of N elements
	ans := make([]bool, N) // Initialize a boolean slice to store the result for each element

	// Read the heights of the elements into the slice H
	for i := 0; i < N; i++ {
		fmt.Scan(&H[i])
		ans[i] = true // Initialize all elements in the boolean slice ans to true
	}

	// Read the pairs of indices (temp1 and temp2) and compare the heights at these indices
	for i := int64(0); i < M; i++ {
		var temp1, temp2 int
		fmt.Scan(&temp1, &temp2)

		if H[temp1-1] < H[temp2-1] {
			ans[temp1-1] = false // Update the boolean slice ans based on the comparison results
		} else if H[temp1-1] > H[temp2-1] {
			ans[temp2-1] = false // Update the boolean slice ans based on the comparison results
		} else {
			ans[temp1-1] = false // Update the boolean slice ans based on the comparison results
			ans[temp2-1] = false // Update the boolean slice ans based on the comparison results
		}
	}

	ans2 := 0 // Initialize a counter to count the number of elements in the boolean slice ans that are still true
	// Count the number of elements in the boolean slice ans that are still true
	for i := 0; i < N; i++ {
		if ans[i] {
			ans2++ // Increment the counter if the element is still true
		}
	}

	fmt.Println(ans2) // Print the count
}

// <END-OF-CODE>
