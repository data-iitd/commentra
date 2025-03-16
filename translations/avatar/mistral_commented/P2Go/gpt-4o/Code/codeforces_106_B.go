package main

import (
	"fmt"
)

func main() {
	// Define the number of items in the input array
	var n int
	fmt.Scan(&n)

	// Initialize a slice to store the input data
	inputArray := make([][4]int, n)

	// Read n items from the standard input and append them to the inputArray
	for i := 0; i < n; i++ {
		fmt.Scan(&inputArray[i][0], &inputArray[i][1], &inputArray[i][2], &inputArray[i][3])
	}

	// Initialize a map to store the outdated items
	outdated := make(map[[4]int]bool)

	// Check for outdated items in the input array
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			// Check if the current item is older and smaller than the next one
			if inputArray[i][0] < inputArray[j][0] &&
				inputArray[i][1] < inputArray[j][1] &&
				inputArray[i][2] < inputArray[j][2] {
				// Mark the current item as outdated
				outdated[inputArray[i]] = true
			}
		}
	}

	// Initialize minimumCost and inputNumber to large initial values
	minimumCost := 100000
	inputNumber := 0

	// Find the item with the minimum cost that is not outdated
	for i := 0; i < n; i++ {
		currentItem := inputArray[i]
		cost := currentItem[3]
		// Check if the current item is not outdated and has a smaller cost than minimumCost
		if !outdated[currentItem] && cost < minimumCost {
			// Update minimumCost and inputNumber
			minimumCost = cost
			inputNumber = i + 1
		}
	}

	// Print the index of the item with the minimum cost that is not outdated
	fmt.Println(inputNumber)
}

// <END-OF-CODE>
