package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const mod = 1000000007

func main() {
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)
	n := len(input)

	if n == 1 {
		if input == "5" || input == "?" {
			fmt.Println(1)
		} else {
			fmt.Println(0)
		}
		return
	}

	// Initialize a 2D slice for dynamic programming
	dp := make([][]int, n)
	for i := range dp {
		dp[i] = make([]int, 13)
	}

	// Fill the dp table based on the characters in input
	for i := 0; i < n; i++ {
		if i == 0 {
			// Handle the first character
			if input[i] != '?' {
				dp[i][atoi(input[i])]++
			} else {
				// If the character is '?', increment counts for all digits (0-9)
				for j := 0; j < 10; j++ {
					dp[i][j]++
				}
			}
		} else {
			// Process subsequent characters
			if input[i] != '?' {
				// If the character is a specific digit
				for k := 0; k < 13; k++ {
					dp[i][(k*10+atoi(input[i]))%13] += dp[i-1][k]
					dp[i][(k*10+atoi(input[i]))%13] %= mod
				}
			} else {
				// If the character is '?', consider all digits (0-9)
				for j := 0; j < 10; j++ {
					for k := 0; k < 13; k++ {
						dp[i][(k*10+j)%13] += dp[i-1][k]
						dp[i][(k*10+j)%13] %= mod
					}
				}
			}
		}
	}

	// Output the count of valid numbers that are divisible by 13 and end with digit 5
	fmt.Println(dp[n-1][5])
}

// Helper function to convert a character to an integer
func atoi(c byte) int {
	num, _ := strconv.Atoi(string(c))
	return num
}
