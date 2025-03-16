package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
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
			costList[i][castNum] = int64(math.Min(float64(costList[i][castNum-1]), float64(srimeList[(i-castNum+N)%N])))
		}
	}

	// Initialize a list to store the final results
	result := make([]int64, N)

	// Calculate the result for each index based on the costs and the value of x
	for i := 0; i < N; i++ {
		result[i] = int64(i) * x + costList[i][0]
		for j := 1; j < N; j++ {
			result[i] += costList[i][j]
		}
	}

	// Print the minimum value from the result list
	fmt.Println(result[0])
	for i := 1; i < N; i++ {
		if result[i] < result[i-1] {
			fmt.Println(result[i])
		}
	}
	fmt.Println(result[N-1])
}

