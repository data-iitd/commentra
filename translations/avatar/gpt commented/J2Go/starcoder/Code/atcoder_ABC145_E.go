package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the number of items (N) and the time limit (T)
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscan(reader, &N, &T)

	// Initialize a 2D array to store the time and value of each item
	AB := make([][]int, N)

	// Read the time and value for each item from the input
	for i := 0; i < N; i++ {
		AB[i] = make([]int, 2)
		fmt.Fscan(reader, &AB[i][0], &AB[i][1])
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
	fmt.Println(max(dp[N]...))
}

func max(nums...int) int {
	max := nums[0]
	for _, num := range nums {
		if num > max {
			max = num
		}
	}
	return max
}

