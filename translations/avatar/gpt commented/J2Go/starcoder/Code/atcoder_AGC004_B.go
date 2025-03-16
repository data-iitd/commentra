package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a new Scanner to read input from stdin
	scanner := bufio.NewScanner(os.Stdin)

	// Read and parse the input from stdin
	var N int
	var x int64
	scanner.Scan()
	N, _ = strconv.Atoi(scanner.Text())
	scanner.Scan()
	x, _ = strconv.ParseInt(scanner.Text(), 10, 64)

	// Initialize a list to store the prime numbers
	srimeList := make([]int64, N)

	// Read N long values into the srimeList
	for i := 0; i < N; i++ {
		scanner.Scan()
		srimeList[i], _ = strconv.ParseInt(scanner.Text(), 10, 64)
	}

	// Initialize a 2D list to store costs
	costList := make([][]int64, N)

	// Create a 2D array for costs, where each row corresponds to an element in srimeList
	for i := 0; i < N; i++ {
		costList[i] = make([]int64, N)
	}

	// Populate the costList with minimum values based on the srimeList
	for i := 0; i < N; i++ {
		// Set the first column of costList to the corresponding values from srimeList
		costList[i][0] = srimeList[i]
		// Calculate the minimum costs for each subsequent column
		for castNum := 1; castNum < N; castNum++ {
			costList[i][castNum] = int64(min(costList[i][castNum-1], srimeList[(i-castNum+N)%N]))
		}
	}

	// Initialize a list to store the final results
	result := make([]int64, N)

	// Calculate the result for each index based on the costs and the value of x
	for i := 0; i < N; i++ {
		j := i
		result[i] = int64(i*x) + int64(sum(costList[i], func(cost int64) int64 {
			return cost
		}))
	}

	// Print the minimum value from the result list
	fmt.Println(min(result))
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func sum(arr []int64, fn func(int64) int64) int64 {
	var total int64
	for _, v := range arr {
		total += fn(v)
	}
	return total
}

