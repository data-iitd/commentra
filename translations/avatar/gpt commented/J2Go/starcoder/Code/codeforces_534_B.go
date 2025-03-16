package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a buffered reader to read input from stdin
	reader := bufio.NewReader(os.Stdin)

	// Read the first line of input from stdin
	line, err := reader.ReadString('\n')
	if err!= nil {
		panic(err)
	}

	// Split the first line of input into individual integers
	v1, v2, t, d := strings.Split(line, " "), 0, 0, 0
	v1[len(v1)-1] = strings.TrimSpace(v1[len(v1)-1])
	v2, _ = strconv.Atoi(v1[0])
	v1, _ = strconv.Atoi(v1[1])
	t, _ = strconv.Atoi(v1[2])
	d, _ = strconv.Atoi(v1[3])

	// Initialize a 2D array dp to store the maximum values for each time step and velocity
	dp := make([][]int, t-1)
	for i := 0; i < t-1; i++ {
		dp[i] = make([]int, 1150)
	}

	// Fill the dp array with a very small value to represent uninitialized states
	for i := 0; i < t-1; i++ {
		for j := 0; j < 1150; j++ {
			dp[i][j] = -1e17
		}
	}

	// Set the initial state for the first time step with the initial velocity
	dp[0][v1] = v1

	// Variable to accumulate the maximum sum of velocities
	sum := 0

	// Iterate through each time step from 1 to t-2
	for i := 1; i < t-1; i++ {
		// Iterate through each possible velocity
		for j := 0; j < 1150; j++ {
			// Update the dp array for increasing velocities
			for x := 0; x <= d; x++ {
				if j+x < 1150 {
					dp[i][j] = max(dp[i][j], dp[i-1][j+x]+j)
				}
			}
			// Update the dp array for decreasing velocities
			for x := d; x >= 0; x-- {
				if j-x >= 0 {
					dp[i][j] = max(dp[i][j], dp[i-1][j-x]+j)
				}
			}
		}
	}

	// Variable to store the final answer, initialized to the smallest possible value
	ans := -1e17

	// Iterate through the last time step to find the maximum achievable velocity close to v2
	for i := t-2; i < t-1; i++ {
		for j := 0; j < 1150; j++ {
			// Check if the current velocity is within the allowed range of v2
			if abs(j-v2) <= d {
				ans = max(ans, dp[i][j]+v2)
			}
		}
	}

	// Output the final answer
	fmt.Println(ans)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}

