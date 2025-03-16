package main

import (
	"fmt"
	"sort"
)

func main() {
	var n int
	fmt.Scan(&n) // Read the size of the array
	v := make([]int, 100010) // Initialize the array to store the values
	for i := 0; i < n; i++ {
		fmt.Scan(&v[i]) // Read the values into the array
	}

	vo := make([]int, 100010) // Initialize arrays to count odd and even numbers
	ve := make([]int, 100010)
	vt := make([]int, 100010)

	for i := 0; i < n; i++ {
		vt[v[i]]++ // Count all numbers
		if i%2 == 0 {
			ve[v[i]]++ // Count even numbers
		} else {
			vo[v[i]]++ // Count odd numbers
		}
	}

	sort.Sort(sort.Reverse(sort.IntSlice(vo))) // Sort the count arrays in descending order
	sort.Sort(sort.Reverse(sort.IntSlice(ve)))
	sort.Sort(sort.Reverse(sort.IntSlice(vt)))

	ans := 0
	if vo[0]+ve[0] == vt[0] { // Check if the maximum counts are consecutive
		ans = min(n-vo[0]-ve[1], n-vo[1]-ve[0]) // Calculate the minimum difference
	} else {
		ans = n - vo[0] - ve[0] // Calculate the difference if not consecutive
	}
	fmt.Println(ans) // Print the result
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// <END-OF-CODE>
