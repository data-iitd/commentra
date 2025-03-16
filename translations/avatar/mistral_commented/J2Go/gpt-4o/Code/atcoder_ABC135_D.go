package main

import (
	"fmt"
	"math"
)

const MOD = int64(1e9 + 7)

func main() {
	run()
}

func run() {
	var input string
	fmt.Scan(&input) // Read the input string
	cs := []rune(input) // Convert the string to a slice of runes
	n := len(cs)
	dp := make([][]int64, n) // Create a 2D slice dp of size n x 13
	for i := range dp {
		dp[i] = make([]int64, 13)
	}
	base := int64(1) // Initialize the base variable to 1

	// Iterate through each character in the character array cs
	for i := 0; i < n; i++ {
		if cs[n-1-i] == '?' { // If the current character is a '?'
			for pre := 0; pre < 13; pre++ { // Iterate through all possible values of pre (from 0 to 12)
				for next := 0; next < 10; next++ { // Iterate through all possible values of next (from 0 to 9)
					dp[i][(base*int64(next)+int64(pre))%13] += // Add the contribution of the current character to the dp array
						func() int64 {
							if i > 0 {
								return dp[i-1][pre] // If i is not the first character, add the contribution of the previous character
							}
							if pre == 0 {
								return 1 // If pre is 0, add a constant value of 1
							}
							return 0
						}()
					dp[i][(base*int64(next)+int64(pre))%13] %= MOD // Perform modulo operation to keep the result within the range of MOD
				}
			}
		} else { // If the current character is not a '?'
			next := int(cs[n-1-i] - '0') // Convert the digit character to an integer
			for pre := 0; pre < 13; pre++ { // Iterate through all possible values of pre (from 0 to 12)
				dp[i][(base*int64(next)+int64(pre))%13] += // Add the contribution of the current character to the dp array
					func() int64 {
						if i > 0 {
							return dp[i-1][pre] // If i is not the first character, add the contribution of the previous character
						}
						if pre == 0 {
							return 1 // If pre is 0, add a constant value of 1
						}
						return 0
					}()
				dp[i][(base*int64(next)+int64(pre))%13] %= MOD // Perform modulo operation to keep the result within the range of MOD
			}
		}
		base = (base * 10) % 13 // Multiply the base by 10 and take the result modulo 13 to update the base for the next character
	}

	// Print the final result
	fmt.Println(dp[n-1][5])
}

// <END-OF-CODE>
