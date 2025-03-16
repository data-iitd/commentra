package main

import (
	"fmt"
)

const MOD = 1e9 + 7

func main() {
	// Read the input string
	var input string
	fmt.Scan(&input)

	// Convert the input string to a slice of runes (characters)
	cs := []rune(input)

	// Initialize a 2D slice for dynamic programming to store results
	dp := make([][]int64, len(cs))
	for i := range dp {
		dp[i] = make([]int64, 13)
	}

	// Variable to keep track of the base value for calculations
	base := 1

	// Iterate through the characters of the input from the last to the first
	for i := 0; i < len(cs); i++ {
		if cs[len(cs)-1-i] == '?' {
			// Loop through all possible previous remainders
			for pre := 0; pre < 13; pre++ {
				// Loop through all possible next digits (0-9)
				for next := 0; next < 10; next++ {
					if i > 0 {
						dp[i][(base*next+pre)%13] += dp[i-1][pre]
					} else if pre == 0 {
						dp[i][(base*next+pre)%13] += 1
					}
					// Ensure the result stays within the MOD limit
					dp[i][(base*next+pre)%13] %= int64(MOD)
				}
			}
		} else {
			// If the character is a digit, convert it to an integer
			next := cs[len(cs)-1-i] - '0'
			// Loop through all possible previous remainders
			for pre := 0; pre < 13; pre++ {
				if i > 0 {
					dp[i][(base*int(next)+pre)%13] += dp[i-1][pre]
				} else if pre == 0 {
					dp[i][(base*int(next)+pre)%13] += 1
				}
				// Ensure the result stays within the MOD limit
				dp[i][(base*int(next)+pre)%13] %= int64(MOD)
			}
		}
		// Update the base value for the next iteration (moving to the next digit)
		base = (base * 10) % 13
	}

	// Output the result, which is the number of ways to form a number divisible by 13
	fmt.Println(dp[len(cs)-1][5])
}

// <END-OF-CODE>
