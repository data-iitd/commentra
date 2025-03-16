package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Set the recursion limit to a higher value to handle deep recursions
const maxDepth = 1000000000

func main() {
	// Read the input from stdin
	reader := bufio.NewReader(os.Stdin)
	S, _ := reader.ReadString('\n')
	S = strings.TrimSpace(S)

	// Convert the input string to a slice of integers
	S = strings.Split(S, "")
	S = convertToIntSlice(S)

	// Call the recursive function to count the number of valid numbers
	count := countValidNumbers(S)

	// Output the count of valid numbers
	fmt.Println(count)
}

// Function to convert a slice of strings to a slice of integers
func convertToIntSlice(S []string) []int {
	var SInt []int
	for _, s := range S {
		i, _ := strconv.Atoi(s)
		SInt = append(SInt, i)
	}
	return SInt
}

// Function to count the number of valid numbers that are divisible by 13 and end with digit 5
func countValidNumbers(S []int) int {
	// Initialize a 2D list for dynamic programming
	dp := make([][]int, len(S))
	for i := range dp {
		dp[i] = make([]int, 13)
	}

	// Fill the dp table based on the characters in S
	for i := range S {
		if i == 0 {
			// Handle the first character
			if S[i]!= 5 && S[i]!= 0 {
				dp[i][S[i]] += 1  // Increment the count for the specific digit
			} else {
				// If the character is '?', increment counts for all digits (0-9)
				for j := 0; j < 10; j++ {
					dp[i][j] += 1
			}
		} else {
			// Process subsequent characters
			if S[i]!= 5 && S[i]!= 0 {
				// If the character is a specific digit
				for k := 0; k < 13; k++ {
					dp[i][(k * 10 + S[i]) % 13] += dp[i - 1][k]
			} else {
				// If the character is '?', consider all digits (0-9)
				for j := 0; j < 10; j++ {
					for k := 0; k < 13; k++ {
						dp[i][(k * 10 + j) % 13] += dp[i - 1][k]
			}

			// Apply modulo to keep the values manageable
			for k := 0; k < 13; k++ {
				dp[i][k] %= maxDepth
	}

	// Output the count of valid numbers that are divisible by 13 and end with digit 5
	return dp[len(S) - 1][5]
}

