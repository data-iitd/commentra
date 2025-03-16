package main

import (
	"fmt"
	"math"
)

const mod = 1_000_000_007

func main() {
	var S string
	fmt.Scan(&S)
	n := len(S)

	// Handle the case where the input string length is 1
	if n == 1 {
		if S == "5" || S == "?" {
			fmt.Println(1) // Output 1 if the single character is '5' or '?'
		} else {
			fmt.Println(0) // Output 0 for any other single character
		}
		return
	}

	// Initialize a 2D slice for dynamic programming
	dp := make([][]int, n)
	for i := range dp {
		dp[i] = make([]int, 13)
	}

	// Fill the dp table based on the characters in S
	for i := 0; i < n; i++ {
		if i == 0 {
			// Handle the first character
			if S[i] != '?' {
				dp[i][int(S[i]-'0')] += 1 // Increment the count for the specific digit
			} else {
				// If the character is '?', increment counts for all digits (0-9)
				for j := 0; j < 10; j++ {
					dp[i][j] += 1
				}
			}
		} else {
			// Process subsequent characters
			if S[i] != '?' {
				// If the character is a specific digit
				for k := 0; k < 13; k++ {
					dp[i][(k*10+int(S[i]-'0'))%13] += dp[i-1][k]
				}
			} else {
				// If the character is '?', consider all digits (0-9)
				for j := 0; j < 10; j++ {
					for k := 0; k < 13; k++ {
						dp[i][(k*10+j)%13] += dp[i-1][k]
					}
				}
			}

			// Apply modulo to keep the values manageable
			for k := 0; k < 13; k++ {
				dp[i][k] %= mod
			}
		}
	}

	// Output the count of valid numbers that are divisible by 13 and end with digit 5
	fmt.Println(dp[n-1][5])
}

// <END-OF-CODE>
