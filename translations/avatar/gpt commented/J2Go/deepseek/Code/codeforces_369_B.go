package main

import (
	"fmt"
	"sort"
)

func main() {
	// Create a Scanner object to read input from the user
	var n, k, l, r, sAll, sk int
	fmt.Scan(&n, &k, &l, &r, &sAll, &sk)

	// Call the getPoints method to calculate the points distribution
	ans := getPoints(n, k, l, r, sAll, sk)

	// Print the resulting points distribution
	for _, num := range ans {
		fmt.Print(num, " ")
	}
}

func getPoints(n, k, l, r, sAll, sk int) []int {
	// Initialize an array to hold the points for each element
	ans := make([]int, n)

	// Fill the array with the minimum value l
	for i := 0; i < n; i++ {
		ans[i] = l
	}

	// Adjust the total sum by subtracting the sum of selected elements and the minimum values
	sAll -= sk + (n - k) * l

	// Adjust the sum of selected elements by subtracting the minimum values
	sk -= k * l

	// Distribute the remaining points to the last k elements
	for sk > 0 {
		idx := n - 1
		for sk > 0 && idx >= n-k {
			ans[idx]++ // Increment the points for the selected elements
			sk--       // Decrease the remaining points to distribute
			idx--
		}
	}

	// Distribute the remaining total sum to the first n-k elements
	for sAll > 0 {
		idx := 0
		for sAll > 0 && idx < n-k {
			ans[idx]++ // Increment the points for the non-selected elements
			sAll--     // Decrease the remaining total sum to distribute
			idx++
		}
	}

	// Return the final points distribution
	return ans
}

