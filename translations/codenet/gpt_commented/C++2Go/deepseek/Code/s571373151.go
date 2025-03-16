package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Declare variables for the number of people (n) and the number of food items (m)
	var n, m int
	fmt.Scan(&n, &m) // Input the values of n and m

	// Create a slice to count the number of people who like each food item
	foods := make([]int, m)

	// Create a scanner to read input
	scanner := bufio.NewScanner(os.Stdin)

	// Loop through each person to gather their food preferences
	for i := 0; i < n; i++ {
		var k int // Number of food items the current person likes
		fmt.Scan(&k) // Input the number of food items

		// Loop through each food item liked by the current person
		for j := 0; j < k; j++ {
			var temp int // Temporary variable to hold the food item index
			fmt.Scan(&temp) // Input the food item index
			temp-- // Convert to zero-based index

			// Increment the count for the corresponding food item
			foods[temp]++
		}
	}

	// Initialize a counter for the number of food items liked by all people
	ans := 0
	// Loop through the food counts to find how many are liked by all n people
	for _, elem := range foods {
		if elem == n { // Check if the food item is liked by all n people
			ans++ // Increment the answer if the condition is met
		}
	}

	// Output the total number of food items liked by all people
	fmt.Println(ans)
}

