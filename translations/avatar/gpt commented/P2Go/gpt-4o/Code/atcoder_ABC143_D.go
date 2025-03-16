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

	// Sort the list of integers
	sort.Ints(l)

	// Initialize the answer variable to count valid triplets
	ans := 0

	// Iterate through each pair of elements in the sorted list
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			a := l[i] // First element of the pair
			b := l[j] // Second element of the pair

			// Find the index where a + b would fit in the sorted list
			right := sort.Search(n, func(k int) bool {
				return l[k] >= a+b
			})

			// Find the index where max(a - b, b - a) would fit in the sorted list
			left := sort.Search(n, func(k int) bool {
				return l[k] > max(a-b, b-a)
			})

			// Calculate the number of valid third elements that can form a triplet
			tmp := max(0, right-left)

			// Adjust the count if the indices i or j are within the range of valid third elements
			if left <= i && i < right {
				tmp-- // Exclude the first element if it's counted
			}
			if left <= j && j < right {
				tmp-- // Exclude the second element if it's counted
			}

			// Add the number of valid triplets formed with the current pair (i, j)
			ans += tmp
		}
	}

	// Since each triplet is counted three times, divide the final answer by 3
	fmt.Println(ans / 3)
}

// Helper function to return the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// <END-OF-CODE>
