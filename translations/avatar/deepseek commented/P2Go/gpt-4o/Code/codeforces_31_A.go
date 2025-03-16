package main

import (
	"fmt"
)

func main() {
	var y int
	fmt.Scan(&y) // Take an integer input for variable y

	var arr []int
	var n int
	fmt.Scan(&n) // Read the number of elements in the array
	arr = make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&arr[i]) // Take a list of integers as input and store it in arr
	}

	// Iterate through the list arr using three nested loops
	for i := 0; i < len(arr); i++ {
		for j := 0; j < len(arr); j++ {
			if i == j {
				continue // Skip if i and j are the same index
			}
			for k := 0; k < len(arr); k++ {
				if arr[k] != arr[j] && arr[k] != arr[i] && arr[k] == arr[i]+arr[j] {
					// Check if arr[k] is the sum of arr[i] and arr[j] and different from both
					fmt.Println(k+1, j+1, i+1) // Print the positions of arr[k], arr[j], and arr[i] (1-indexed)
					return // Exit the program
				}
			}
		}
	}
	fmt.Println(-1) // Print -1 if no such element is found
}

// <END-OF-CODE>
