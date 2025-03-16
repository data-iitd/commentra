package main

import (
	"fmt"
	"sort"
)

func main() {
	var n int
	fmt.Scan(&n) // Read the number of elements in the list

	l := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&l[i]) // Read the list of integers
	}

	sort.Ints(l) // Sort the list in ascending order

	for _, i := range l { // Iterate through each element in the sorted list
		if contains(l, i+1) && contains(l, i+2) { // Check if the next two elements are also in the list
			fmt.Println("YES") // If yes, print 'YES' and break out of the loop
			return
		}
	}
	fmt.Println("NO") // If no, print 'NO' after the loop finishes
}

// Helper function to check if a slice contains a specific value
func contains(slice []int, value int) bool {
	for _, v := range slice {
		if v == value {
			return true
		}
	}
	return false
}
