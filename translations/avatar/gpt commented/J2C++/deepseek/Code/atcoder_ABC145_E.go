package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	// Read the number of items (N) and the time limit (T)
	scanner.Scan()
	N := parseInt(scanner.Text())
	scanner.Scan()
	T := parseInt(scanner.Text())

	// Initialize a 2D slice to store the time and value of each item
	AB := make([][]int, N)

	// Read the time and value for each item from the input
	for i := 0; i < N; i++ {
		AB[i] = make([]int, 2)
		scanner.Scan()
		AB[i][0] = parseInt(scanner.Text()) // Time required for the item
		scanner.Scan()
		AB[i][1] = parseInt(scanner.Text()) // Value of the item
	}

	// Sort the items based on the time required in ascending order
	sort.Slice(AB, func(i, j int) bool {
		return AB[i][0] < AB[j][0]
	})

	// Initialize a DP table where dp[i][j] represents the maximum value
	// that can be obtained using the first i items within j time
	dp := make([][]int, N+1)
	for i := 0; i <= N; i++ {
		dp[i] = make([]int, 6001)
	}

	// Fill the DP table
	for i := 1; i <= N; i++ {
		for timeAfterEat := 0; timeAfterEat <= 6000; timeAfterEat++ {
			// Carry forward the maximum value from the previous item
			dp[i][timeAfterEat] = max(dp[i][timeAfterEat], dp[i-1][timeAfterEat])

			// Get the time and value of the current item
			time := AB[i-1][0]
			value := AB[i-1][1]

			// Check if the current item can be taken within the remaining time
			if 0 <= timeAfterEat-time && timeAfterEat-time < T {
				// Update the DP table with the maximum value obtained by taking the current item
				dp[i][timeAfterEat] = max(dp[i][timeAfterEat], dp[i-1][timeAfterEat-time]+value)
			}
		}
	}

	// Output the maximum value that can be obtained using all items
	maxValue := 0
	for _, value := range dp[N] {
		if value > maxValue {
			maxValue = value
		}
	}
	fmt.Println(maxValue)
}

// Helper function to parse string to int
func parseInt(s string) int {
	var num int
	fmt.Sscanf(s, "%d", &num)
	return num
}

// Helper function to get the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

