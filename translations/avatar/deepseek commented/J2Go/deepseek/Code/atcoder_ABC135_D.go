package main

import (
	"fmt"
	"strings"
)

func main() {
	new Main().run()
}

// MOD constant with value 10^9 + 7
const MOD = 1000000007

// Main logic of the program
func (m Main) run() {
	var sc = strings.NewReader(readString())
	var cs []rune
	for {
		r, _, err := sc.ReadRune()
		if err != nil {
			break
		}
		cs = append(cs, r)
	}

	// 2D slice dp to store the number of ways to achieve each remainder when the number is divided by 13
	var dp = make([][]int, len(cs))
	for i := range dp {
		dp[i] = make([]int, 13)
	}

	// Initialize the base variable to represent the current power of 10
	var base int = 1

	// Loop through the character array from the least significant digit to the most significant digit
	for i := 0; i < len(cs); i++ {
		if cs[len(cs)-1-i] == '?' {
			// If the current character is '?', we iterate through all possible digits (0-9)
			for pre := 0; pre < 13; pre++ {
				for next := 0; next < 10; next++ {
					dp[i][(base*next+pre)%13] += (i > 0 ? dp[i-1][pre] : (pre == 0 ? 1 : 0))
					dp[i][(base*next+pre)%13] %= MOD
				}
			}
		} else {
			// If the current character is not '?', we update the dp array based on the actual digit
			next := int(cs[len(cs)-1-i] - '0')
			for pre := 0; pre < 13; pre++ {
				dp[i][(base*next+pre)%13] += (i > 0 ? dp[i-1][pre] : (pre == 0 ? 1 : 0))
				dp[i][(base*next+pre)%13] %= MOD
			}
		}
		// Update the base variable to the next power of 10 modulo 13
		base = base * 10 % 13
	}

	// Print the number of ways to achieve the remainder 5 when the number is divided by 13
	fmt.Println(dp[len(dp)-1][5])
}

// Method to read input as a string (for simplicity)
func readString() string {
	return "your_input_string_here"
}
