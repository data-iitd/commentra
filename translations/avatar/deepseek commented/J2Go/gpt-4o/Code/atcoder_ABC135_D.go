package main

import (
	"fmt"
)

const MOD = 1e9 + 7

func main() {
	var input string
	fmt.Scan(&input)

	cs := []rune(input)
	n := len(cs)

	// 2D slice dp to store the number of ways to achieve each remainder when the number is divided by 13
	dp := make([][]int64, n)
	for i := range dp {
		dp[i] = make([]int64, 13)
	}

	// Initialize the base variable to represent the current power of 10
	base := 1

	// Loop through the character array from the least significant digit to the most significant digit
	for i := 0; i < n; i++ {
		if cs[n-1-i] == '?' {
			// If the current character is '?', we iterate through all possible digits (0-9)
			for pre := 0; pre < 13; pre++ {
				for next := 0; next < 10; next++ {
					if i > 0 {
						dp[i][(base*next+pre)%13] += dp[i-1][pre]
					} else {
						if pre == 0 {
							dp[i][(base*next+pre)%13]++
						}
					}
					dp[i][(base*next+pre)%13] %= int64(MOD)
				}
			}
		} else {
			// If the current character is not '?', we update the dp array based on the actual digit
			next := int(cs[n-1-i] - '0')
			for pre := 0; pre < 13; pre++ {
				if i > 0 {
					dp[i][(base*next+pre)%13] += dp[i-1][pre]
				} else {
					if pre == 0 {
						dp[i][(base*next+pre)%13]++
					}
				}
				dp[i][(base*next+pre)%13] %= int64(MOD)
			}
		}
		// Update the base variable to the next power of 10 modulo 13
		base = (base * 10) % 13
	}

	// Print the number of ways to achieve the remainder 5 when the number is divided by 13
	fmt.Println(dp[n-1][5])
}

// <END-OF-CODE>
