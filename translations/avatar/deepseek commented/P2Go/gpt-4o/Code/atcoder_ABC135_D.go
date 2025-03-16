package main

import (
	"fmt"
	"math"
)

const mod = 1e9 + 7

func main() {
	var S string
	fmt.Scan(&S) // Read input string
	n := len(S)  // Get length of the string

	if n == 1 { // Check if the string length is 1
		if S == "5" || S == "?" { // Check if the string is '5' or '?'
			fmt.Println(1) // Print 1 if true
		} else {
			fmt.Println(0) // Print 0 otherwise
		}
		return // Exit the program
	}

	dp := make([][13]int, n) // Initialize dp array

	for i := 0; i < n; i++ { // Iterate over the length of the string
		if i == 0 { // Base case for the first character
			if S[i] != '?' { // Check if the character is not '?'
				dp[i][int(S[i]-'0')]++ // Update dp value directly
			} else {
				for j := 0; j < 10; j++ { // Iterate over all possible digits
					dp[i][j]++ // Increment dp value
				}
			}
		} else { // General case for subsequent characters
			if S[i] != '?' { // Check if the character is not '?'
				for k := 0; k < 13; k++ { // Iterate over all possible remainders
					dp[i][(k*10+int(S[i]-'0'))%13] += dp[i-1][k] // Update dp value
				}
			} else {
				for j := 0; j < 10; j++ { // Iterate over all possible digits
					for k := 0; k < 13; k++ { // Iterate over all possible remainders
						dp[i][(k*10+j)%13] += dp[i-1][k] // Update dp value
					}
				}
			}
			for k := 0; k < 13; k++ { // Apply modulo to prevent overflow
				dp[i][k] %= int(mod)
			}
		}
	}
	fmt.Println(dp[n-1][5]) // Print the result
}

// <END-OF-CODE>
