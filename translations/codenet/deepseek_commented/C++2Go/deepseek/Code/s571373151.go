package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscan(reader, &n, &m) // Read the number of people and the number of food types

	 foods := make([]int, m) // Initialize a slice to keep track of food counts

	for i := 0; i < n; i++ { // Loop through each person
		var k int
		fmt.Fscan(reader, &k) // Read the number of food preferences for this person

		for j := 0; j < k; j++ { // Loop through each food preference
			var temp int
			fmt.Fscan(reader, &temp) // Read the type of food
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

