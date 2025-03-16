package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the first integer value: ")
	v1, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	fmt.Println("Enter the second integer value: ")
	v2, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	fmt.Println("Enter the number of time steps: ")
	t, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	fmt.Println("Enter the maximum difference between two consecutive values: ")
	d, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))

	dp := make([][]int, t-1) // Creating a 2D array dp of size (t-1) x 1150 for dynamic programming table

	// Initializing the first row of the dp table with the given value
	for i := 0; i < t-1; i++ {
		dp[i] = make([]int, 1150)
		for j := 0; j < 1150; j++ {
			dp[i][j] = -1000000000
		}
		dp[i][v1] = v1
	}

	sum := 0

	// Filling the dp table using dynamic programming
	for i := 1; i < t-1; i++ {
		for j := 0; j < 1150; j++ {
			for x := 0; x <= d; x++ {
				dp[i][j] = max(dp[i][j], dp[i-1][j+x]+j)
			}
			for x := d; x >= 0; x-- {
				dp[i][j] = max(dp[i][j], dp[i-1][j-x]+j)
			}
		}
		sum += dp[i][1149]
	}

	ans := -1000000000

	// Finding the maximum value that can be obtained by jumping from any cell in the last but one row to the last row and adding the value of the last cell of the last row
	for i := t-2; i < t-1; i++ {
		for j := 0; j < 1150; j++ {
			if abs(j-v2) <= d {
				ans = max(ans, dp[i][j]+v2)
			}
		}
	}

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

