package main

import (
	"fmt" // Importing the fmt package for formatted I/O
)

func main() {
	var n, k, l, r, sAll, sk int

	// Reading input values from the user
	fmt.Scan(&n)   // Reading the number of points n
	fmt.Scan(&k)   // Reading the number of points to be removed k
	fmt.Scan(&l)   // Reading the length l of each segment
	fmt.Scan(&r)   // Reading the radius r of each circle
	fmt.Scan(&sAll) // Reading the total score before removing points
	fmt.Scan(&sk)   // Reading the score contributed by the k points to be removed

	// Calling the getPoints function to get the updated scores of all points
	ans := getPoints(n, k, l, r, sAll, sk)

	// Printing the updated scores of all points
	for _, num := range ans {
		fmt.Print(num, " ") // Printing each updated score followed by a space
	}

	fmt.Println() // Printing a newline after printing all scores
}

// getPoints calculates the updated scores of all points
func getPoints(n, k, l, r, sAll, sk int) []int {
	ans := make([]int, n) // Initializing a slice ans of size n to store the updated scores of all points

	// Filling the initial scores of all points with the value l
	for i := range ans {
		ans[i] = l
	}

	// Calculating the remaining score after removing the given k points and segments of length l
	sAll -= sk + (n-k)*l

	// Removing the score of the given k points
	sk -= k * l

	// Finding the indices of the points to be increased in the first loop
	idx := n - 1
	for sk > 0 && idx >= n-k {
		ans[idx]++ // Increasing the score of the current point by 1
		sk--       // Decreasing the remaining score by 1
		idx--      // Moving to the previous point
	}

	// Finding the indices of the points to be increased in the second loop
	for sAll > 0 {
		idx = 0
		for sAll > 0 && idx < n-k {
			ans[idx]++ // Increasing the score of the current point by 1
			sAll--     // Decreasing the remaining score by 1
			idx++      // Moving to the next point
		}
	}

	// Returning the updated scores of all points as a slice
	return ans
}

// <END-OF-CODE>
