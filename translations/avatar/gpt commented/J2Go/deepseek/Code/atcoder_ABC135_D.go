package main

import (
	"fmt"
	"strings"
)

func main() {
	// Create an instance of Main and run the main logic
	mainInstance := new(Main)
	mainInstance.run()
}

// Define a constant for the modulo operation
const MOD = 1e9 + 7

type Main struct{}

func (m *Main) run() {
	// Initialize a scanner to read input
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	// Read the input string and convert it to a character array
	cs := []rune(scanner.Text())
	
	// Initialize a 2D array for dynamic programming to store results
	dp := make([][]int, len(cs))
	for i := range dp {
		dp[i] = make([]int, 13)
	}
	
	// Variable to keep track of the base value for calculations
	base := 1
	
	// Iterate through the characters of the input from the last to the first
	for i := 0; i < len(cs); i++ {
		// Check if the current character is a '?', which can be any digit
		if cs[len(cs)-1-i] == '?' {
			// Loop through all possible previous remainders
			for pre := 0; pre < 13; pre++ {
				// Loop through all possible next digits (0-9)
				for next := 0; next < 10; next++ {
					// Update the dp array for the current position and remainder
					dp[i][(base*next+pre)%13] += (i > 0 ? dp[i-1][pre] : (pre == 0 ? 1 : 0))
					// Ensure the result stays within the MOD limit
					dp[i][(base*next+pre)%13] %= int(MOD)
				}
			}
		} else {
			// If the character is a digit, convert it to an integer
			next := int(cs[len(cs)-1-i] - '0')
			// Loop through all possible previous remainders
			for pre := 0; pre < 13; pre++ {
				// Update the dp array for the current position and remainder
				dp[i][(base*next+pre)%13] += (i > 0 ? dp[i-1][pre] : (pre == 0 ? 1 : 0))
				// Ensure the result stays within the MOD limit
				dp[i][(base*next+pre)%13] %= int(MOD)
			}
		}
		// Update the base value for the next iteration (moving to the next digit)
		base = base * 10 % 13
	}
	
	// Output the result, which is the number of ways to form a number divisible by 13
	fmt.Println(dp[len(dp)-1][5])
}
