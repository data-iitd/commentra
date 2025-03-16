package main

import (
	"fmt"
	"math"
)

func main() {
	// Reading the number of test cases
	var n int
	fmt.Scan(&n)

	// Declaring an integer slice dp of size 200001 to store the position of each number in the sequence
	dp := make([]int, 200001)

	// Initializing a variable ans to store the answer
	var ans int64 = 0

	// Iterating through each test case
	for i := 0; i < n; i++ {
		// Reading the next number to be added to the sequence
		var num int
		fmt.Scan(&num)

		// Storing the position of the number in the dp slice
		dp[num] = i
	}

	// Calculating the answer by iterating through the dp slice and finding the absolute difference between the positions of consecutive numbers
	for i := 2; i <= n; i++ {
		// Adding the absolute difference to the answer
		ans += int64(math.Abs(float64(dp[i] - dp[i-1])))
	}

	// Printing the answer to the console
	fmt.Println(ans)
}

// <END-OF-CODE>
