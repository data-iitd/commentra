
package main

import (
	"fmt"
)

// Set the modulus value
const mod = 1000000007

// Read input values for n and k
var n, k int
fmt.Scan(&n, &k)

// Initialize a list 'coef' to store coefficients
var coef []int

// Calculate coefficients for n up to its square root
for i := 1; i <= int(n**0.5)+1; i++ {
	// Calculate the difference between the quotient and the next quotient
	coef = append(coef, n/i-n/(i+1))
}

// Add remaining coefficients to the list
for i := len(coef); i < n; i++ {
	coef = append(coef, 1)
}

// Reverse the list 'coef'
for i, j := 0, len(coef)-1; i < j; i, j = i+1, j-1 {
	coef[i], coef[j] = coef[j], coef[i]
}

// Initialize a 2D list 'dp' to store intermediate results
var nn = len(coef)
var dp [][]int
for i := 0; i < k+1; i++ {
	dp = append(dp, make([]int, nn))
}

// Initialize the first row of dp with 1 at index 0
dp[0][0] = 1

// Calculate dp[i][j] for i from 1 to k and j from nn-1 to 0
for i := 1; i <= k; i++ {
	tmp := 0
	// Iterate through the reverse list 'coef' from j = nn-1 to j = 0
	for j := nn - 1; j >= 0; j-- {
		// Update 'tmp' with the sum of dp[i-1][j] and the product of coef[j] and tmp
		tmp += dp[i-1][j]
		tmp = (tmp + coef[j]) % mod
		// Update dp[i][j] with the product of coef[j] and tmp
		dp[i][j] = coef[j] * tmp
		dp[i][j] %= mod
	}
}

// Calculate the final answer by summing up dp[k]
var ans int
for i := 0; i < nn; i++ {
	ans += dp[k][i]
	ans %= mod
}

// Print the final answer
fmt.Println(ans)

// 