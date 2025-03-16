package main

import (
	"fmt"
	"sort"
)

func main() {
	var n int
	fmt.Scan(&n) // Read the number of elements in the list

	l1 := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&l1[i]) // Read the list elements
	}

	sort.Ints(l1) // Sort the list in ascending order

	a := l1[n-1] // Assign the last element of the sorted list to the variable a
	b := l1[0]   // Assign the first element of the sorted list to the variable b

	if a == b { // Check if the first and the last elements are equal
		fmt.Println(a-b, (n*(n-1))/2) // If so, calculate and print the result
	} else {
		ac := countOccurrences(l1, a) // Count the number of occurrences of the element a in the list
		bc := countOccurrences(l1, b) // Count the number of occurrences of the element b in the list
		fmt.Println(a-b, ac*bc)        // Print the result
	}
}

// Function to count occurrences of a value in a slice
func countOccurrences(slice []int, value int) int {
	count := 0
	for _, v := range slice {
		if v == value {
			count++
		}
	}
	return count
}
