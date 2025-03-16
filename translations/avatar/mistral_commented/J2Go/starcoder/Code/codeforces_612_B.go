package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function to calculate the answer
func calculateAnswer(dp []int) int {
	// Initializing an integer variable ans to store the answer
	ans := 0

	// Iterating through the dp array and finding the absolute difference between the positions of consecutive numbers
	for i := 2; i <= len(dp); i++ {
		// Adding the absolute difference to the answer
		ans += abs(dp[i] - dp[i-1])
	}

	// Returning the answer
	return ans
}

// Function to find the absolute difference between two numbers
func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

// Main function
func main() {
	// Reading the number of test cases
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter the number of test cases: ")
	tc, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))

	// Declaring an integer array dp of size 200001 to store the position of each number in the sequence
	dp := make([]int, 200001)

	// Iterating through each test case
	for i := 0; i < tc; i++ {
		// Reading the next number to be added to the sequence
		fmt.Print("Enter the next number to be added to the sequence: ")
		num, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))

		// Storing the position of the number in the dp array
		dp[num] = i
	}

	// Calculating the answer
	ans := calculateAnswer(dp)

	// Printing the answer to the console
	fmt.Println(ans)
}

