package main

import (
	"fmt"
)

func main() {
	// Read the number of items from user input
	var n int
	fmt.Scan(&n)

	// Initialize a slice to store the input items
	inputArray := make([][4]int, n)

	// Loop to read each item's attributes (S, R, H, C)
	for i := 0; i < n; i++ {
		fmt.Scan(&inputArray[i][0], &inputArray[i][1], &inputArray[i][2], &inputArray[i][3])
	}

	// Initialize a map to keep track of outdated items
	outdated := make(map[[4]int]bool)

	// Compare each item with every other item to find outdated ones
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			// Check if item i is outdated compared to item j
			if inputArray[i][0] < inputArray[j][0] &&
				inputArray[i][1] < inputArray[j][1] &&
				inputArray[i][2] < inputArray[j][2] {
				// If outdated, add item i to the outdated map
				outdated[inputArray[i]] = true
			}
		}
	}

	// Initialize variables to track the minimum cost and corresponding item index
	minimumCost := 100000
	inputNumber := 0

	// Loop through the input items to find the one with the minimum cost that is not outdated
	for i := 0; i < n; i++ {
		currentItem := inputArray[i]
		cost := currentItem[3] // Get the cost of the current item
		// Check if the current item is not outdated and has a lower cost than the current minimum
		if !outdated[currentItem] && cost < minimumCost {
			minimumCost = cost // Update the minimum cost
			inputNumber = i + 1 // Store the index of the current item (1-based index)
		}
	}

	// Print the index of the item with the minimum cost that is not outdated
	fmt.Println(inputNumber)
}

// <END-OF-CODE>
