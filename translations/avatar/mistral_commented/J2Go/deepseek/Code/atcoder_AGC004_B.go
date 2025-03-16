package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	var N int
	var x int64

	// Reading input from the console
	scanner.Scan()
	N, _ = strconv.Atoi(scanner.Text())
	scanner.Scan()
	x, _ = strconv.ParseInt(scanner.Text(), 10, 64)

	// Creating a slice to store the elements
	srimeList := make([]int64, N)

	// Reading elements of the array and adding them to the slice
	for i := 0; i < N; i++ {
		scanner.Scan()
		srimeList[i], _ = strconv.ParseInt(scanner.Text(), 10, 64)
	}

	// Creating a slice to store the cost arrays
	costList := make([][]int64, N)

	// Creating cost arrays of size N x N for each element in the original array
	for i := 0; i < N; i++ {
		costList[i] = make([]int64, N)
	}

	// Filling the cost arrays with the minimum cost for each index and each cast number
	for i := 0; i < N; i++ {
		costList[i][0] = srimeList[i] // Setting the first element of the cost array to the original element
		for castNum := 1; castNum < N; castNum++ {
			costList[i][castNum] = min(costList[i][castNum-1], srimeList[(i-castNum+N)%N])
		}
	}

	// Creating a slice to store the final result
	result := make([]int64, N)

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
	for _, value := range result {
		if value < minResult {
			minResult = value
		}
	}

	// Printing the minimum result
	fmt.Println(minResult)
}

// Helper function to find the minimum of two integers
func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

