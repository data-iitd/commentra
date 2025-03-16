package main

import (
	"fmt"
	"sort"
)

func main() {
	var n int
	fmt.Scan(&n)

	l := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&l[i])
	}

	// Sort the list 'l' in ascending order
	sort.Ints(l)

	// Initialize an answer variable 'ans' to zero
	ans := 0

	// Iterate through each pair of indices 'i' and 'j' in the list 'l'
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			// Assign the elements at indices 'i' and 'j' to variables 'a' and 'b' respectively
			a := l[i]
			b := l[j]

			// Use binary search to find the index 'right' where an element greater than 'a+b' is present
			right := sort.Search(n, func(k int) bool {
				return l[k] >= a+b
			})

			// Use binary search to find the index 'left' where the smallest element greater than 'max(a-b, b-a)' is present
			left := sort.Search(n, func(k int) bool {
				return l[k] > max(a-b, b-a)
			})

			// Calculate the temporary answer 'tmp' based on the indices 'left' and 'right'
			tmp := max(0, right-left)

			// Subtract one from the temporary answer 'tmp' if both 'i' and 'j' lie between 'left' and 'right'
			if left <= i && i < right {
				tmp--
			}
			if left <= j && j < right {
				tmp--
			}

			// Add the temporary answer 'tmp' to the final answer 'ans'
			ans += tmp
		}
	}

	// Print the final answer 'ans' divided by three
	fmt.Println(ans / 3)
}

// Helper function to find the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// <END-OF-CODE>
