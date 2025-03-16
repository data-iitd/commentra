package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	// Read the number of items (N) and the maximum time (T)
	line, _ := reader.ReadString('\n')
	parts := strings.Split(strings.TrimSpace(line), " ")
	N, _ := strconv.Atoi(parts[0])
	T, _ := strconv.Atoi(parts[1])

	// Initialize a slice to store time and value pairs, starting with a dummy entry
	timeValue := [][]int{{0, 0}}

	// Read the time and value pairs for each item
	for i := 0; i < N; i++ {
		line, _ := reader.ReadString('\n')
		parts := strings.Split(strings.TrimSpace(line), " ")
		time, _ := strconv.Atoi(parts[0])
		value, _ := strconv.Atoi(parts[1])
		timeValue = append(timeValue, []int{time, value})
	}

	// Sort the timeValue slice based on the value (VAL)
	sort.Slice(timeValue, func(i, j int) bool {
		return timeValue[i][1] < timeValue[j][1]
	})

	// Initialize a 2D slice for dynamic programming, with -1 as default values
	dp := make([][]int, N+1)
	for i := range dp {
		dp[i] = make([]int, T)
		for j := range dp[i] {
			dp[i][j] = -1
		}
	}

	// Base case: If time is 0, the maximum value is 0 for all items
	for t := 0; t < T; t++ {
		dp[0][t] = 0
	}

	// Fill the dynamic programming table
	for n := 1; n <= N; n++ {
		// Base case: If no time is available, the maximum value is 0
		dp[n][0] = 0
		for t := 1; t < T; t++ {
			// If the current item's time exceeds the available time, skip the item
			if timeValue[n][0] > t {
				dp[n][t] = dp[n-1][t]
			} else {
				// Choose the maximum between not taking the item and taking it
				dp[n][t] = max(dp[n-1][t], timeValue[n][1]+dp[n-1][t-timeValue[n][0]])
			}
		}
	}

	// Initialize the maximum value with the last item's value
	valAcum := timeValue[N][1]
	t := T - 1
	maxVal := valAcum + dp[N-1][t]

	// Backtrack to find the maximum value considering previous items
	for n := N - 1; n > 0; n-- {
		valAcum += timeValue[n][1]
		t -= timeValue[n+1][0]

		// If time goes negative, break the loop
		if t < 0 {
			break
		} else {
			// Update the maximum value if a better option is found
			maxVal = max(maxVal, valAcum+dp[n-1][t])
		}
	}

	// Print the maximum value achievable within the given time
	fmt.Println(maxVal)
}

// Helper function to return the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

