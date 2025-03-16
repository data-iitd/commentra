
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read input from standard input
	reader := bufio.NewReader(os.Stdin)

	// Constants to represent indices for time and value
	const TIME = 0
	const VAL = 1

	// Read the number of items (N) and the maximum time (T)
	line, _ := reader.ReadString('\n')
	tokens := strings.Split(line, " ")
	N, _ := strconv.Atoi(tokens[0])
	T, _ := strconv.Atoi(tokens[1])

	// Initialize a list to store time and value pairs, starting with a dummy entry
	timeValue := make([][2]int, N+1)
	timeValue[0] = [2]int{-1, -1}

	// Read the time and value pairs for each item
	for i := 1; i <= N; i++ {
		line, _ := reader.ReadString('\n')
		tokens := strings.Split(line, " ")
		time, _ := strconv.Atoi(tokens[0])
		value, _ := strconv.Atoi(tokens[1])
		timeValue[i] = [2]int{time, value}
	}

	// Sort the timeValue list based on the value (VAL)
	for i := 1; i <= N; i++ {
		for j := i; j > 0 && timeValue[j][VAL] > timeValue[j-1][VAL]; j-- {
			timeValue[j], timeValue[j-1] = timeValue[j-1], timeValue[j]
		}
	}

	// Initialize a 2D list for dynamic programming, with -1 as default values
	dp := make([][]int, N+1)
	for i := 0; i <= N; i++ {
		dp[i] = make([]int, T+1)
		for j := 0; j <= T; j++ {
			dp[i][j] = -1
		}
	}

	// Base case: If time is 0, the maximum value is 0 for all items
	for t := 0; t <= T; t++ {
		dp[0][t] = 0
	}

	// Fill the dynamic programming table
	for n := 1; n <= N; n++ {
		// Base case: If no time is available, the maximum value is 0
		dp[n][0] = 0
		for t := 1; t <= T; t++ {
			// If the current item's time exceeds the available time, skip the item
			if timeValue[n][TIME] > t {
				dp[n][t] = dp[n-1][t]
			} else {
				// Choose the maximum between not taking the item and taking it
				dp[n][t] = max(dp[n-1][t], timeValue[n][VAL]+dp[n-1][t-timeValue[n][TIME]])
			}
		}
	}

	// Initialize the maximum value with the last item's value
	valAcum := timeValue[N][VAL]
	t := T - 1
	maxVal := valAcum + dp[N-1][t]

	// Backtrack to find the maximum value considering previous items
	for n := N - 1; n > 0; n-- {
		valAcum += timeValue[n][VAL]
		t -= timeValue[n+1][TIME]

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

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

