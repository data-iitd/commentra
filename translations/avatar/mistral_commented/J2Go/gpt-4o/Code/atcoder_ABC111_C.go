package main

import (
	"fmt"
	"sort"
)

func main() {
	var n int
	fmt.Scan(&n) // Reading the number of elements 'n' from the standard input

	v := make([]int, 100010) // Declaring an integer slice 'v' of size 100010 to store the input elements

	// Reading the elements of the array 'v' from the standard input
	for i := 0; i < n; i++ {
		fmt.Scan(&v[i])
	}

	vo := make([]int, 100010) // Slice to store counts of occurrences of unique values in odd indexed elements
	ve := make([]int, 100010) // Slice to store counts of occurrences of unique values in even indexed elements
	vt := make([]int, 100010) // Slice to store total counts of occurrences of unique values

	// Counting occurrences in odd indexed elements
	for i := 0; i < n; i += 2 {
		currentElement := v[i]
		vo[currentElement]++
	}

	// Counting occurrences in even indexed elements
	for i := 1; i < n; i += 2 {
		currentElement := v[i]
		ve[currentElement]++
	}

	// Sorting the slices in descending order
	sort.Slice(vo, func(i, j int) bool {
		return vo[i] > vo[j]
	})
	sort.Slice(ve, func(i, j int) bool {
		return ve[i] > ve[j]
	})
	sort.Slice(vt, func(i, j int) bool {
		return vt[i] > vt[j]
	})

	ans := 0 // Variable to store the answer

	// Checking if the sum of the first elements of the slices 'vo' and 've' is equal to the first element of the slice 'vt'
	if vo[0]+ve[0] == vt[0] {
		// Calculating the answer as the minimum of the difference between the total number of elements and the sum of the counts of the first elements of the slices 'vo' and 've'
		ans = min(n-vo[0]-ve[1], n-vo[1]-ve[0])
	} else {
		// Calculating the answer as the difference between the count of the first element of the slice 'vo' and the count of the first element of the slice 've'
		ans = n - vo[0] - ve[0]
	}

	// Printing the answer to the standard output
	fmt.Println(ans)
}

// Helper function to find the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// <END-OF-CODE>
