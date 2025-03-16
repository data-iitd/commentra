package main

import (
	"fmt"
	"math"
)

func main() {
	var N int
	var x int64

	// Read the number of elements (N) and a long value (x) from input
	fmt.Scan(&N, &x)

	// Initialize a slice to store the prime numbers
	srimeList := make([]int64, N)

	// Read N long values into the srimeList
	for i := 0; i < N; i++ {
		fmt.Scan(&srimeList[i])
	}

	// Initialize a 2D slice to store costs
	costList := make([][]int64, N)
	for i := 0; i < N; i++ {
		costList[i] = make([]int64, N)
	}

	// Populate the costList with minimum values based on the srimeList
	for i := 0; i < N; i++ {
		// Set the first column of costList to the corresponding values from srimeList
		costList[i][0] = srimeList[i]
		// Calculate the minimum costs for each subsequent column
		for castNum := 1; castNum < N; castNum++ {
			costList[i][castNum] = int64(math.Min(float64(costList[i][castNum-1]), float64(srimeList[(i-castNum+N)%N])))
		}
	}

	// Initialize a slice to store the final results
	result := make([]int64, N)

	// Calculate the result for each index based on the costs and the value of x
	for i := 0; i < N; i++ {
		sum := int64(0)
		for j := 0; j < N; j++ {
			sum += costList[j][i]
		}
		result[i] = int64(i)*x + sum
	}

	// Find the minimum value from the result slice
	minValue := result[0]
	for _, val := range result {
		if val < minValue {
			minValue = val
		}
	}

	// Print the minimum value from the result list
	fmt.Println(minValue)
}

// <END-OF-CODE>
