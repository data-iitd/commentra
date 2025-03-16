
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read input from stdin
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the number of coins")
	n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	fmt.Println("Enter the value of coins")
	a, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	b, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	c, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))

	// Initialize a dp array with all elements set to Integer.MIN_VALUE
	dp := make([]int, 4010)
	for i := 0; i < 4010; i++ {
		dp[i] = -1000000000
	}

	// Set the base case where dp[0] is 0
	dp[0] = 0

	// Iterate over the coin values and update the dp array
	for i := 0; i < 3; i++ {
		for j := a; j < 4010; j++ {
			if dp[j-a]!= -1000000000 {
				dp[j] = max(dp[j], dp[j-a]+1)
			}
		}
	}

	// Print the value of dp[n]
	fmt.Println(dp[n])
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

