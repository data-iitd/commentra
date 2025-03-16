package main

import (
	"fmt"
	"os"
	"strconv"
)

func run() {
	var n, k int // Declare variables for the number of elements and the target value
	// Read the number of elements and the target value from input
	fmt.Scan(&n, &k)

	a := make([]int, n) // Array to store the elements
	var i, j int // Loop variables

	// Read the elements into the array
	for i = 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	dp := make([]int, k+1) // Allocate memory for the dynamic programming array

	// Iterate over each possible value from 1 to k
	for i = 1; i <= k; i++ {
		win := 0 // Variable to determine if the current player can win

		// Check each element to see if it can lead to a winning position
		for j = 0; j < n && a[j] <= i; j++ {
			// If there exists a move that leads to a losing position for the opponent
			if dp[i-a[j]] == 0 {
				win = 1 // Current player can win
			}
		}

		// Store the result in the dp array: 1 if the current player can win, 0 otherwise
		dp[i] = win
	}

	// Output the result: "First" if the first player can win, otherwise "Second"
	fmt.Println(dp[k] ? "First" : "Second")
}

func main() {
	run() // Call the run function to execute the game logic
	os.Exit(0) // Return success
}

