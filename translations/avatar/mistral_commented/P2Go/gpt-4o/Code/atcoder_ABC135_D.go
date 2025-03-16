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

	// Base case: if the length of the string is 1
	if n == 1 {
		if S == "5" || S == "?" {
			fmt.Println(1)
		} else {
			fmt.Println(0)
		}
		return
	}

	// Initialize a 2D slice dp of size (n, 13) with all elements initialized to 0
	dp := make([][]int, n)
	for i := range dp {
		dp[i] = make([]int, 13)
	}

	// Iterate through each index i from 0 to n-1
	for i := 0; i < n; i++ {
		// If i is the first index, process it differently
		if i == 0 {
			if S[i] != '?' {
				dp[i][int(S[i]-'0')]++
			} else {
				for j := 0; j < 10; j++ {
					dp[i][j]++
				}
			}
		} else {
			// If the character at index i is not '?', update the dp array accordingly
			if S[i] != '?' {
				for k := 0; k < 13; k++ {
					dp[i][(k*10+int(S[i]-'0'))%13] += dp[i-1][k]
					dp[i][(k*10+int(S[i]-'0'))%13] %= mod
				}
			} else {
				for j := 0; j < 10; j++ {
					for k := 0; k < 13; k++ {
						dp[i][(k*10+j)%13] += dp[i-1][k]
						dp[i][(k*10+j)%13] %= mod
					}
				}
			}
		}
	}

	// Print the final answer, which is dp[n-1][5]
	fmt.Println(dp[n-1][5])
}

// <END-OF-CODE>
