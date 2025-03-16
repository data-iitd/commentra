package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n) // Take the number of elements as input
	inputArray := make([][4]int, n) // Initialize a slice to store tuples

	// Loop to take inputs and append them as tuples to inputArray
	for i := 0; i < n; i++ {
		fmt.Scan(&inputArray[i][0], &inputArray[i][1], &inputArray[i][2], &inputArray[i][3]) // Take four integers as input
	}

	outdated := make(map[[4]int]bool) // Initialize a map to store outdated elements

	// Nested loop to compare each element in inputArray with every other element
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if inputArray[i][0] < inputArray[j][0] &&
				inputArray[i][1] < inputArray[j][1] &&
				inputArray[i][2] < inputArray[j][2] {
				outdated[inputArray[i]] = true // Mark the element as outdated
			}
		}
	}

	minimumCost := 100000 // Initialize minimumCost to a large value
	inputNumber := 0      // Initialize inputNumber to 0

	// Iterate through inputArray to find the item with the minimum cost that is not outdated
	for i := 0; i < n; i++ {
		currentItem := inputArray[i]
		cost := currentItem[3]
		if !outdated[currentItem] && cost < minimumCost {
			minimumCost = cost // Update minimumCost
			inputNumber = i + 1 // Update inputNumber
		}
	}

	fmt.Println(inputNumber) // Print the input number of the item with the minimum cost that is not outdated
}

// <END-OF-CODE>
