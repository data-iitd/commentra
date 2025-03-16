package main

import (
	"fmt"
)

func main() {
	var N int
	var M int64

	fmt.Scan(&N) // Reading the number of elements in the array H
	fmt.Scan(&M) // Reading the number of queries

	H := make([]int64, N) // Creating a slice of size N to store the heights
	ans := make([]bool, N) // Creating a boolean slice of size N to store the answer for each index

	for i := 0; i < N; i++ { // Reading the elements of the array H
		fmt.Scan(&H[i])
		ans[i] = true // Initially assuming that all elements are in the left half
	}

	for query := int64(0); query < M; query++ { // Processing each query
		var temp1, temp2 int
		fmt.Scan(&temp1, &temp2) // Reading the first and second index

		if H[temp1-1] < H[temp2-1] { // If the height of the first index is less than the second index
			ans[temp1-1] = false // The first index cannot be in the left half
		} else if H[temp1-1] > H[temp2-1] { // If the height of the first index is greater than the second index
			ans[temp2-1] = false // The second index cannot be in the left half
		} else { // If the heights are equal
			ans[temp1-1] = false // Both the first and second indices cannot be in the left half
			ans[temp2-1] = false
		}
	}

	ans2 := 0 // Initializing a counter to store the number of elements in the left half
	for i := 0; i < N; i++ { // Iterating through the slice to find the number of elements in the left half
		if ans[i] { // If an element is still assumed to be in the left half
			ans2++ // Increment the counter
		}
	}

	fmt.Println(ans2) // Printing the final answer
}

// <END-OF-CODE>
