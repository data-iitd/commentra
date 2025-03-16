package main

import (
	"fmt"
	"math"
)

func main() {
	var N int
	var x int64
	fmt.Scan(&N) // Read the number of elements N
	fmt.Scan(&x) // Read the cost multiplier x

	srimeList := make([]int64, N) // Create a slice to store the elements
	for i := 0; i < N; i++ {
		fmt.Scan(&srimeList[i]) // Read N long integers and add to srimeList
	}

	costList := make([][]int64, N) // Create a slice of slices to store costs
	for i := 0; i < N; i++ {
		costList[i] = make([]int64, N) // Initialize each slice in costList with size N
	}

	// Fill costList with the minimum costs for each element in srimeList
	for i := 0; i < N; i++ {
		costList[i][0] = srimeList[i] // Initialize the first element of the cost array
		for castNum := 1; castNum < N; castNum++ {
			costList[i][castNum] = int64(math.Min(float64(costList[i][castNum-1]), float64(srimeList[(i-castNum+N)%N])))
		}
	}

	result := make([]int64, N) // Create a slice to store the final results
	for i := 0; i < N; i++ {
		j := i // Use a local variable to avoid closure issues
		sum := int64(0)
		for _, costArray := range costList {
			sum += costArray[j]
		}
		result[i] = int64(i)*x + sum
	}

	// Find the minimum cost found
	minCost := result[0]
	for _, cost := range result {
		if cost < minCost {
			minCost = cost
		}
	}
	fmt.Println(minCost)
}

// <END-OF-CODE>
