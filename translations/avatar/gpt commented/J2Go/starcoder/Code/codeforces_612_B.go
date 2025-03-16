package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a buffered reader to read input from the console
	reader := bufio.NewReader(os.Stdin)
	
	// Read the number of elements to be processed
	n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	
	// Initialize a dp array to store the indices of the input elements
	dp := make([]int, 200001)
	
	// Populate the dp array with the indices of the input elements
	for i := 0; i < n; i++ {
		// Read the next integer and store its index in the dp array
		dp[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	}
	
	// Initialize a variable to accumulate the result
	ans := 0
	
	// Calculate the total distance between consecutive elements in the dp array
	for i := 2; i <= n; i++ {
		// Add the absolute difference of indices of consecutive elements to ans
		ans += abs(dp[i] - dp[i - 1])
	}
	
	// Output the final result
	fmt.Println(ans)
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

