package main

import (
	"fmt"
)

func main() {
	var len int
	fmt.Scan(&len) // Read the length of the array
	a := make([]int, len)
	for i := 0; i < len; i++ {
		fmt.Scan(&a[i]) // Read the elements of the array
	}
	l := 0 // Initialize the starting index of the misplaced element
	r := 0 // Initialize the ending index of the misplaced element
	flag := false // Flag to indicate the start of the misplaced segment
	isTrue := false // Flag to indicate if the segment is unsorted
	for i := 0; i < len; i++ {
		if a[i] != i+1 && !flag { // Check for the first misplaced element
			l = i + 1 // Set the starting index
			flag = true // Set the flag to true
			continue // Continue to the next iteration
		}
		if a[i] != i+1 && flag { // Check for the second misplaced element
			r = i + 1 // Set the ending index
			if (a[r-1] - a[r-2] > 0) { // Check if the segment is unsorted
				isTrue = true // Set the flag to true
				break // Break out of the loop
			}
		}
	}
	fmt.Println((!isTrue) ? fmt.Sprintf("%d %d", l, r) : "0 0") // Print the indices or "0 0" if no such segment exists
}

