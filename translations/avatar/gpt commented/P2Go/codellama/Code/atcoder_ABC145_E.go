package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read input from standard input
	input := os.Stdin.ReadString('\n')

	// Constants to represent indices for time and value
	const TIME = 0
	const VAL = 1

	// Read the number of items (N) and the maximum time (T)
	N, T := readInts(input)

	// Initialize a list to store time and value pairs, starting with a dummy entry
	timeValue := make([][2]int, N + 1)
	timeValue[0] = [2]int{-1, -1}

	// Read the time and value pairs for each item
	for i := 1; i <= N; i++ {
		timeValue[i] = readInts(os.Stdin.ReadString('\n'))
	}

	// Sort the timeValue list based on the value (VAL)
	sort(timeValue, VAL)

	// Initialize a 2D list for dynamic programming, with -1 as default values
	dp := make([][]int, N + 1)
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
			if timeValue[n][TIME] > t {
				dp[n][t] = dp[n - 1][t]
			} else {
				// Choose the maximum between not taking the item and taking it
				dp[n][t] = max(dp[n - 1][t], timeValue[n][VAL] + dp[n - 1][t - timeValue[n][TIME]])
			}
		}
	}

	// Initialize the maximum value with the last item's value
	valAcum := timeValue[N][VAL]
	t := T - 1
	maxVal := valAcum + dp[N - 1][t]

	// Backtrack to find the maximum value considering previous items
	for n := N - 1; n > 0; n-- {
		valAcum += timeValue[n][VAL]
		t -= timeValue[n + 1][TIME]

		// If time goes negative, break the loop
		if t < 0 {
			break
		} else {
			// Update the maximum value if a better option is found
			maxVal = max(maxVal, valAcum + dp[n - 1][t])
		}
	}

	// Print the maximum value achievable within the given time
	fmt.Println(maxVal)
}

func readInts(input string) (int, int) {
	// Split the input into two integers
	ints := strings.Split(input, " ")

	// Convert the integers to int
	N, _ := strconv.Atoi(ints[0])
	T, _ := strconv.Atoi(ints[1])

	return N, T
}

func sort(timeValue [][2]int, val int) {
	// Sort the timeValue list based on the value (VAL)
	for i := 1; i < len(timeValue); i++ {
		for j := i; j > 0 && timeValue[j][val] > timeValue[j - 1][val]; j-- {
			timeValue[j], timeValue[j - 1] = timeValue[j - 1], timeValue[j]
		}
	}
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

