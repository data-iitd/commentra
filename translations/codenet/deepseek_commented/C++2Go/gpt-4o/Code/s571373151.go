package main

import (
	"fmt"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m) // Read the number of people and the number of food types

	foods := make([]int, m) // Initialize a slice to keep track of food counts

	for i := 0; i < n; i++ { // Loop through each person
		var k int
		fmt.Scan(&k) // Read the number of food preferences for this person

		for j := 0; j < k; j++ { // Loop through each food preference
			var temp int
			fmt.Scan(&temp) // Read the type of food
			temp-- // Adjust the food type to be 0-indexed

			foods[temp]++ // Increment the count of this food type
		}
	}

	ans := 0 // Initialize a counter for food types preferred by all people

	for _, elem := range foods { // Loop through each food type count
		if elem == n { // Check if the food type is preferred by all people
			ans++ // Increment the counter
		}
	}

	fmt.Println(ans) // Output the number of food types preferred by all people
}

// <END-OF-CODE>
