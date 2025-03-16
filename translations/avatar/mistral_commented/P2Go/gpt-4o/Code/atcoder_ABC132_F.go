package main

import (
	"fmt"
	"math"
)

const mod = 1000000007

func main() {
	var n, k int
	fmt.Scan(&n, &k)

	// Initialize a slice 'coef' to store coefficients
	coef := []int{}

	// Calculate coefficients for n up to its square root
	for i := 1; i <= int(math.Sqrt(float64(n))); i++ {
		coef = append(coef, n/i-n/(i+1))
	}

	// Add remaining coefficients to the slice
	coef = append(coef, make([]int, n-sum(coef))...)

	// Reverse the slice 'coef'
	for i, j := 0, len(coef)-1; i < j; i, j = i+1, j-1 {
		coef[i], coef[j] = coef[j], coef[i]
	}

	// Initialize a 2D slice 'dp' to store intermediate results
	dp := make([][]int, k+1)
	for i := range dp {
		dp[i] = make([]int, len(coef))
	}

	// Initialize the first row of dp with 1 at index 0
	dp[0][0] = 1

	// Calculate dp[i][j] for i from 1 to k and j from nn-1 to 0
	for i := 1; i <= k; i++ {
		tmp := 0
		// Iterate through the reverse slice 'coef' from j = nn-1 to j = 0
		for j := len(coef) - 1; j >= 0; j-- {
			// Update 'tmp' with the sum of dp[i-1][j] and the product of coef[j] and tmp
			tmp = (tmp + dp[i-1][j]) % mod
			tmp = (tmp + coef[j]) % mod
			// Update dp[i][j] with the product of coef[j] and tmp
			dp[i][j] = (coef[j] * tmp) % mod
		}
	}

	// Calculate the final answer by summing up dp[k]
	result := 0
	for _, value := range dp[k] {
		result = (result + value) % mod
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

// <END-OF-CODE>
