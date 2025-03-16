package main

import (
	"fmt"
)

func main() {
	// Declare variables
	var n, m int
	fmt.Scan(&n, &m)

	// Initialize a slice of size m to store the count of each food item
	foods := make([]int, m)

	// Read n food preferences from the standard input
	for i := 0; i < n; i++ {
		var k int

		// Read the number of food items in the current preference
		fmt.Scan(&k)

		// Read the indices of the food items in the current preference
		for j := 0; j < k; j++ {
			var temp int

			// Read the index of the current food item
			fmt.Scan(&temp)

			// Increment the count of the corresponding food item in the foods slice
			foods[temp]++
		}
	}

	// Initialize a variable to store the number of food items that appear in all preferences
	ans := 0

	// Iterate through each element in the foods slice and check if its count is equal to the total number of preferences
	for _, elem := range foods {
		if elem == n {
			ans++
		}
	}

	// Print the value of ans to the standard output
	fmt.Println(ans)
}

// <END-OF-CODE>
