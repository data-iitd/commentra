
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Create a scanner to read input from the console
	scan := bufio.NewScanner(os.Stdin)

	// Read the number of elements (N) and a long value (x) from input
	scan.Scan()
	N, _ := strconv.Atoi(scan.Text())
	scan.Scan()
	x, _ := strconv.ParseInt(scan.Text(), 10, 64)

	// Initialize a list to store the prime numbers
	srimeList := make([]int64, N)

	// Read N long values into the srimeList
	for i := 0; i < N; i++ {
		scan.Scan()
		srimeList[i], _ = strconv.ParseInt(scan.Text(), 10, 64)
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
			costList[i][castNum] = int64(min(int(costList[i][castNum-1]), int(srimeList[(i-castNum+N)%N])))
		}
	}

	// Initialize a list to store the final results
	result := make([]int64, N)

	// Calculate the result for each index based on the costs and the value of x
	for i := 0; i < N; i++ {
		finalI := i // Final variable for lambda expression
		result[i] = int64(i*x + sum(costList, finalI))
	}

	// Print the minimum value from the result list
	fmt.Println(min(result...))
}

func min(a...int) int {
	m := a[0]
	for _, v := range a {
		if v < m {
			m = v
		}
	}
	return m
}

func sum(costList [][]int64, i int) int {
	s := 0
	for _, v := range costList {
		s += int(v[i])
	}
	return s
}

// Translate the above Go code to C++ and end with comment "