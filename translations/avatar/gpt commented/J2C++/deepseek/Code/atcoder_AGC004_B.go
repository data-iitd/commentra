package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Create a Scanner object to read input from the console
	scanner := bufio.NewScanner(os.Stdin)
	
	// Read the number of elements (N) and a long value (x) from input
	scanner.Scan()
	N, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	x, _ := strconv.ParseInt(scanner.Text(), 10, 64)
	
	// Initialize a list to store the prime numbers
	srimeList := make([]int64, N)
	
	// Read N long values into the srimeList
	for i := 0; i < N; i++ {
		scanner.Scan()
		srimeList[i], _ = strconv.ParseInt(scanner.Text(), 10, 64)
	}
	
	// Initialize a 2D list to store costs
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
			costList[i][castNum] = min(costList[i][castNum - 1], srimeList[(i - castNum + N) % N])
		}
	}
	
	// Initialize a list to store the final results
	result := make([]int64, N)
	
	// Calculate the result for each index based on the costs and the value of x
	for i := 0; i < N; i++ {
		var sum int64 = 0
		for j := 0; j < N; j++ {
			sum += costList[j][i]
		}
		result[i] = int64(i) * x + sum
	}
	
	// Print the minimum value from the result list
	minResult := result[0]
	for _, v := range result {
		if v < minResult {
			minResult = v
		}
	}
	fmt.Println(minResult)
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

