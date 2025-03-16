
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Declare variables for the number of people (n) and the number of food items (m)
	n, m := readTwoInt() // Read the values of n and m

	// Create a slice to count the number of people who like each food item
	foods := make([]int, m)

	// Loop through each person to gather their food preferences
	for i := 0; i < n; i++ {
		k := readInt() // Read the number of food items

		// Loop through each food item liked by the current person
		for j := 0; j < k; j++ {
			temp := readInt() - 1 // Read the food item index and convert to zero-based index

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

func readInt() int {
	// Read an integer from the input
	scanner := bufio.NewScanner(os.Stdin)
	if scanner.Scan() {
		num, err := strconv.Atoi(scanner.Text())
		if err!= nil {
			panic(err)
		}
		return num
	}
	panic("No input found")
}

func readTwoInt() (int, int) {
	// Read two integers from the input
	return readInt(), readInt()
}

