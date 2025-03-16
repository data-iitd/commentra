package main

import (
	"fmt"
	"sort"
)

func main() {
	var num, k int
	fmt.Scan(&num, &k) // Read the number of elements and the divisor

	arr := make([]int, num)
	for i := 0; i < num; i++ {
		fmt.Scan(&arr[i]) // Read the array of integers
	}

	different := make(map[int]struct{}) // Initialize a map to keep track of unique elements not divisible by k
	temp := 0                             // Initialize a variable to store the maximum length of the map

	sort.Ints(arr) // Sort the array

	// Iterate through each element in the sorted array
	for _, x := range arr {
		if x%k != 0 || _, exists := different[x/k]; !exists { // Check if x is not divisible by k or x/k is not in the map
			different[x] = struct{}{} // Add x to the map if the condition is true
		}
		temp = max(len(different), temp) // Update temp with the maximum length of the map
	}

	fmt.Println(temp) // Print the maximum number of unique elements not divisible by k
}

// Helper function to find the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// <END-OF-CODE>
