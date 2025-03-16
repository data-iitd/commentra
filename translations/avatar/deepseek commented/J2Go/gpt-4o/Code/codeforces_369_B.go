package main

import (
	"fmt"
)

func main() {
	var n, k, l, r, sAll, sk int
	fmt.Scan(&n, &k, &l, &r, &sAll, &sk) // Reading input values

	ans := getPoints(n, k, l, r, sAll, sk) // Calling the getPoints function

	for _, num := range ans { // Iterating through the result slice to print each element
		fmt.Print(num, " ") // Printing each element followed by a space
	}
}

func getPoints(n, k, l, r, sAll, sk int) []int {
	ans := make([]int, n) // Initializing a slice to store the result
	for i := range ans {
		ans[i] = l // Filling the slice with the lower bound value 'l'
	}

	// Subtracting the initial points for the first group and the remaining elements
	sAll -= sk + (n-k)*l
	sk -= k * l

	// Distributing the remaining points to the first group until sk is zero
	for sk > 0 {
		idx := n - 1 // Starting from the last element in the slice
		for sk > 0 && idx >= n-k {
			ans[idx]++ // Incrementing the points
			sk-- // Decrementing the remaining points to distribute
			idx-- // Moving to the previous element
		}
	}

	// Distributing the remaining points to the remaining elements until sAll is zero
	for sAll > 0 {
		idx := 0 // Starting from the first element in the slice
		for sAll > 0 && idx < n-k {
			ans[idx]++ // Incrementing the points
			sAll-- // Decrementing the remaining points to distribute
			idx++ // Moving to the next element
		}
	}

	return ans // Returning the result slice
}

// <END-OF-CODE>
