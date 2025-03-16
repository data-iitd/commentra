package main

import (
	"fmt"
)

const mod = 1000000007 // Set the modulus to 10^9 + 7

func main() {
	var n, k int
	fmt.Scan(&n, &k) // Read the values of n and k from input

	// Calculate the coefficients for the number of multiples of each divisor up to n
	coef := make([]int, 0)
	for i := 1; i*i <= n; i++ {
		coef = append(coef, (n/i)-(n/(i+1))) // Calculate the number of multiples of i
	}
	coef = append(coef, make([]int, n-sum(coef))...) // Adjust for remaining numbers
	reverse(coef) // Reverse the coefficients for dynamic programming

	nn := len(coef) // Get the length of the coefficient list
	dp := make([][]int, k+1) // Initialize the dp table
	for i := range dp {
		dp[i] = make([]int, nn)
	}
	dp[0][0] = 1 // Base case: one way to achieve sum 0 with 0 elements

	// Dynamic programming to calculate the number of ways to achieve sums with up to k elements
	for i := 1; i <= k; i++ {
		tmp := 0 // Temporary variable to accumulate the sum of previous row's values
		for j := nn - 1; j >= 0; j-- {
			tmp += dp[i-1][nn-1-j] // Update the temporary sum
			tmp %= mod
			dp[i][j] = coef[j] * tmp // Update the dp table
			dp[i][j] %= mod
		}
	}

	// Print the result: the sum of the last row of dp modulo mod
	result := 0
	for _, val := range dp[k] {
		result += val
		result %= mod
	}
	fmt.Println(result)
}

// Helper function to sum the elements of a slice
func sum(arr []int) int {
	total := 0
	for _, v := range arr {
		total += v
	}
	return total
}

// Helper function to reverse a slice
func reverse(arr []int) {
	for i, j := 0, len(arr)-1; i < j; i, j = i+1, j-1 {
		arr[i], arr[j] = arr[j], arr[i]
	}
}

// <END-OF-CODE>
