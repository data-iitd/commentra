########
# Code #
########

// Import necessary libraries
package main

import (
	"fmt"
	"math"
)

// Define the modulus value
const mod = 1000000007

// Function to read an integer
func I() int {
	var n int
	fmt.Scan(&n)
	return n
}

// Function to read a list of integers
func III() []int {
	var n int
	fmt.Scan(&n)
	a := make([]int, n)
	for i := range a {
		fmt.Scan(&a[i])
	}
	return a
}

// Function to read a list of lists (2D array)
func Line(n int) [][]int {
	a := make([][]int, n)
	for i := range a {
		a[i] = make([]int, n)
		for j := range a[i] {
			fmt.Scan(&a[i][j])
		}
	}
	return a
}

// Input the string S and its length n
var S string
var n int

// Base case: if the length of the string is 1
if n == 1 {
	// Check if the string is '5' or '?' and print 1 if true, else print 0
	if S == "5" || S == "?" {
		fmt.Println(1)
	} else {
		fmt.Println(0)
		return
	}
}

// Initialize a 2D array dp of size (n, 13) with all elements initialized to 0
var dp [][]int

// Iterate through each index i from 0 to n-1
for i := 0; i < n; i++ {
	// If i is the first index, process it differently
	if i == 0 {
		// If the character at index i is not '?', update the dp array accordingly
		if S[i] != '?' {
			dp[i][int(S[i])] += 1
		}
		// If the character at index i is '?', update all elements in the dp array accordingly
		else {
			for j := 0; j < 10; j++ {
				dp[i][j] += 1
			}
		}
	}
	// If i is not the first index, process it differently
	else {
		// If the character at index i is not '?', update the dp array accordingly
		if S[i] != '?' {
			for k := 0; k < 13; k++ {
				dp[i][(k*10+int(S[i]))%13] += dp[i-1][k]
			}
		}
		// If the character at index i is '?', update all elements in the dp array accordingly
		else {
			for j := 0; j < 10; j++ {
				for k := 0; k < 13; k++ {
					dp[i][(k*10+j)%13] += dp[i-1][k]
				}
			}
			// Update all elements in the dp array with the current value modulo mod
			for k := 0; k < 13; k++ {
				dp[i][k] %= mod
			}
		}
	}
}

// Print the final answer, which is dp[n-1][5]
fmt.Println(dp[n-1][5])

