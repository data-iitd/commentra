
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Create a scanner to read input from the console
	s := bufio.NewScanner(os.Stdin)
	
	// Read the number of elements to be processed
	s.Scan()
	n := int(mustParseInt(s.Text()))
	
	// Initialize a dp array to store the indices of the input elements
	dp := make([]int, 200001)
	
	// Populate the dp array with the indices of the input elements
	for i := 0; i < n; i++ {
		// Read the next integer and store its index in the dp array
		s.Scan()
		dp[mustParseInt(s.Text())] = i
	}
	
	// Initialize a variable to accumulate the result
	ans := int64(0)
	
	// Calculate the total distance between consecutive elements in the dp array
	for i := 2; i <= n; i++ {
		// Add the absolute difference of indices of consecutive elements to ans
		ans += int64(abs(dp[i]-dp[i-1]))
	}
	
	// Output the final result
	fmt.Println(ans)
}

func mustParseInt(s string) int {
	n, err := strconv.Atoi(s)
	if err!= nil {
		panic(err)
	}
	return n
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

