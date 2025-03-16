package main

import (
	"fmt"
	"sort"
)

func main() {
	var n int
	fmt.Scan(&n) // Take an integer input for the number of elements

	l := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&l[i]) // Take a list of integers as input
	}

	sort.Ints(l) // Sort the list of integers

	// Check if there exists any integer i in the list such that i + 1 and i + 2 are also in the list
	for _, i := range l {
		if contains(l, i+1) && contains(l, i+2) { // Check if i + 1 and i + 2 are in the list
			fmt.Println("YES") // If found, print 'YES' and break the loop
			return
		}
	}
	fmt.Println("NO") // If no such integer is found, print 'NO'
}

// Helper function to check if a slice contains a specific integer
func contains(slice []int, value int) bool {
	for _, v := range slice {
		if v == value {
			return true
		}
	}
	return false
}
