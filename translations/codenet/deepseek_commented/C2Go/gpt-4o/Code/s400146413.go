package main

import (
	"fmt"
)

// LinearSearch function
// Purpose: This function performs a linear search to find the key in the array S.
// Parameters:
//   - S: The array to be searched.
//   - key: The value to be searched for.
// Return Value: Returns true if the key is found, otherwise returns false.
func linearSearch(S []int, key int) bool {
	for _, value := range S {
		if value == key {
			return true
		}
	}
	return false
}

// Main function
// Purpose: This function reads two arrays S and T, and counts the number of elements in T that are present in S using the linearSearch function.
func main() {
	var n, q int
	var count int

	fmt.Scan(&n)
	S := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&S[i])
	}

	fmt.Scan(&q)
	T := make([]int, q)
	for j := 0; j < q; j++ {
		fmt.Scan(&T[j])
	}

	for j := 0; j < q; j++ {
		key := T[j]
		if !linearSearch(S, key) {
			count++
		}
	}

	fmt.Println(count)
}

// <END-OF-CODE>
