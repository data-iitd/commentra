package main

import (
	"fmt"
	"math"
)

func main() {
	var n int
	fmt.Scan(&n)
	cs := make([]byte, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&cs[i])
	}

	// 2D array dp to store the number of ways to achieve each remainder when the number is divided by 13
	dp := make([][]int, n)
	for i := 0; i < n; i++ {
		dp[i] = make([]int, 13)
	}

	// Initialize the base variable to represent the current power of 10
	base := 1

	// Loop through the character array from the least significant digit to the most significant digit
	for i := 0; i < n; i++ {
		if cs[n-1-i] == '?' {
			// If the current character is '?', we iterate through all possible digits (0-9)
			for pre := 0; pre < 13; pre++ {
				for next := 0; next < 10; next++ {
					dp[i][(base*next+pre)%13] += (i > 0 ? dp[i-1][pre] : (pre == 0 ? 1 : 0))
					dp[i][(base*next+pre)%13] %= 1000000007
				}
			}
		} else {
			// If the current character is not '?', we update the dp array based on the actual digit
			next := int(cs[n-1-i] - '0')
			for pre := 0; pre < 13; pre++ {
				dp[i][(base*next+pre)%13] += (i > 0 ? dp[i-1][pre] : (pre == 0 ? 1 : 0))
				dp[i][(base*next+pre)%13] %= 1000000007
			}
		}
		// Update the base variable to the next power of 10 modulo 13
		base = int(math.Pow(10, float64(i+1)) % 13)
	}

	// Print the number of ways to achieve the remainder 5 when the number is divided by 13
	fmt.Println(dp[n-1][5])
}

// 