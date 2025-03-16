package main

import (
	"fmt"
)

func main() {
	// Declaring an integer array dp of size 200001 to store the position of each number in the sequence
	var dp [200001]int

	// Initializing a long variable ans to store the answer
	var ans int64 = 0

	// Reading the number of test cases
	var n int
	fmt.Scan(&n)

	// Iterating through each test case
	for i := 0; i < n; i++ {
		// Reading the next number to be added to the sequence
		var num int
		fmt.Scan(&num)

		// Storing the position of the number in the dp array
		dp[num] = i
	}

	// Calculating the answer by iterating through the dp array and finding the absolute difference between the positions of consecutive numbers
	for i := 2; i <= n; i++ {
		// Adding the absolute difference to the answer
		ans += int64(math.Abs(float64(dp[i] - dp[i-1])))
	}

	// Printing the answer to the console
	fmt.Println(ans)
}
