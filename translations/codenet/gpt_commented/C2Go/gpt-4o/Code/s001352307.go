package main

import (
	"fmt"
)

func main() {
	// Global variables to hold the weight limit (W) and number of items (N)
	var W, N int
	// Array to store the input items with their weights and values
	input := make([][2]int, 1024)

	// Infinite loop to process multiple test cases
	for t := 0; ; t++ {
		// Initialize the ans and input arrays to zero for each test case
		ans := make([][2]int, 1024)

		// Read the weight limit (W) and number of items (N)
		fmt.Scanf("%d%d", &W, &N)
		// Break the loop if the weight limit is zero (end of input)
		if W == 0 {
			break
		}

		// Read the value and weight of each item
		for i := 0; i < N; i++ {
			fmt.Scanf("%d,%d", &input[i][0], &input[i][1])
		}

		// Dynamic programming to calculate the maximum value for each capacity
		for i := 0; i < N; i++ {
			// Traverse the capacities in reverse to avoid overwriting results
			for j := 1023; j >= input[i][1]; j-- {
				// Check if including the current item increases the maximum value
				if ans[j][0] < input[i][0]+ans[j-input[i][1]][0] {
					// Update the maximum value and corresponding weight
					ans[j][0] = input[i][0] + ans[j-input[i][1]][0]
					ans[j][1] = input[i][1] + ans[j-input[i][1]][1]
				}
			}
		}

		// Find the maximum value and corresponding weight for the exact weight limit
		j := 0
		for ans[W][0] == ans[W-j-1][0] {
			j++
		}

		// Print the results for the current test case
		fmt.Printf("Case %d:\n%d\n%d\n", t+1, ans[W-j][0], ans[W-j][1])
	}
}

// <END-OF-CODE>
