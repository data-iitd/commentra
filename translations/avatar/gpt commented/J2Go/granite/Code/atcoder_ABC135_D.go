
package main

import (
	"bufio"
	"fmt"
	"os"
)

const MOD = 1000000007

func main() {
	// Create a scanner to read input
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)

	// Read the input string and convert it to a character array
	cs := []byte(sc.Text())

	// Initialize a 2D array for dynamic programming to store results
	dp := make([][]int64, len(cs))
	for i := range dp {
		dp[i] = make([]int64, 13)
	}

	// Variable to keep track of the base value for calculations
	base := 1

	// Iterate through the characters of the input from the last to the first
	for i := len(cs) - 1; i >= 0; i-- {
		// Check if the current character is a '?', which can be any digit
		if cs[i] == '?' {
			// Loop through all possible previous remainders
			for pre := 0; pre < 13; pre++ {
				// Loop through all possible next digits (0-9)
				for next := 0; next < 10; next++ {
					// Update the dp array for the current position and remainder
					dp[i][(base*next+pre)%13] += dp[i+1][pre]
					// Ensure the result stays within the MOD limit
					dp[i][(base*next+pre)%13] %= MOD
				}
			}
		} else {
			// If the character is a digit, convert it to an integer
			next := int(cs[i] - '0')
			// Loop through all possible previous remainders
			for pre := 0; pre < 13; pre++ {
				// Update the dp array for the current position and remainder
				dp[i][(base*next+pre)%13] += dp[i+1][pre]
				// Ensure the result stays within the MOD limit
				dp[i][(base*next+pre)%13] %= MOD
			}
		}
		// Update the base value for the next iteration (moving to the next digit)
		base = base * 10 % 13
	}

	// Output the result, which is the number of ways to form a number divisible by 13
	fmt.Println(dp[0][5])
}

