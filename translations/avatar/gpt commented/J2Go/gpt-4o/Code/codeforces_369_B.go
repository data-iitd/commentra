package main

import (
	"fmt"
)

func main() {
	// Read the number of elements (n), number of selected elements (k),
	// lower bound (l), upper bound (r), total sum (sAll), and sum of selected elements (sk)
	var n, k, l, r, sAll, sk int
	fmt.Scan(&n, &k, &l, &r, &sAll, &sk)

	// Call the getPoints function to calculate the points distribution
	ans := getPoints(n, k, l, r, sAll, sk)

	// Print the resulting points distribution
	for _, num := range ans {
		fmt.Print(num, " ")
	}
}

func getPoints(n, k, l, r, sAll, sk int) []int {
	// Initialize a slice to hold the points for each element
	ans := make([]int, n)

	// Fill the slice with the minimum value l
	for i := range ans {
		ans[i] = l
	}

	// Adjust the total sum by subtracting the sum of selected elements and the minimum values
	sAll -= sk + (n-k)*l

	// Adjust the sum of selected elements by subtracting the minimum values
	sk -= k * l

	// Distribute the remaining points to the last k elements
	for sk > 0 {
		for idx := n - 1; idx >= n-k && sk > 0; idx-- {
			ans[idx]++ // Increment the points for the selected elements
			sk--       // Decrease the remaining points to distribute
		}
	}

	// Distribute the remaining total sum to the first n-k elements
	for sAll > 0 {
		for idx := 0; idx < n-k && sAll > 0; idx++ {
			ans[idx]++ // Increment the points for the non-selected elements
			sAll--     // Decrease the remaining total sum to distribute
		}
	}

	// Return the final points distribution
	return ans
}

// <END-OF-CODE>
