package main

import (
	"fmt"
	"math"
)

func main() {
	var N int // Variable to store the number of elements in the array
	var x int64 // Variable to store the multiplier

	// Reading input from the console
	fmt.Scan(&N)
	fmt.Scan(&x)

	srimeList := make([]int64, N) // Creating a slice to store the elements

	// Reading elements of the array and adding them to the slice
	for i := 0; i < N; i++ {
		fmt.Scan(&srimeList[i])
	}

	costList := make([][]int64, N) // Creating a slice of slices to store the cost arrays

	// Creating cost arrays of size N x N for each element in the original array
	for i := 0; i < N; i++ {
		costList[i] = make([]int64, N)
		costList[i][0] = srimeList[i] // Setting the first element of the cost array to the original element
		for castNum := 1; castNum < N; castNum++ {
			costList[i][castNum] = int64(math.Min(float64(costList[i][castNum-1]), float64(srimeList[(i-castNum+N)%N])))
		}
	}

	result := make([]int64, N) // Creating a slice to store the final result

	// Calculating the result for each index and adding it to the slice
	for i := 0; i < N; i++ {
		temp := int64(i) * x // Multiplying the index with the multiplier
		for _, cost := range costList[i] { // Iterating through the cost array and adding the costs
			temp += cost
		}
		result[i] = temp
	}

	// Finding the minimum result
	minResult := result[0]
	for _, val := range result {
		if val < minResult {
			minResult = val
		}
	}

	// Printing the minimum result
	fmt.Println(minResult)
}

// <END-OF-CODE>
