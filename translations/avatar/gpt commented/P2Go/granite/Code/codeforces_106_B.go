
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the number of items from user input
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))

	// Initialize an empty list to store the input items
	inputArray := make([][]int, n)

	// Loop to read each item's attributes (S, R, H, C)
	for i := 0; i < n; i++ {
		// Read the attributes S, R, H, C and convert them to integers
		line := readLine(reader)
		attributes := strings.Split(line, " ")
		S, _ := strconv.Atoi(attributes[0])
		R, _ := strconv.Atoi(attributes[1])
		H, _ := strconv.Atoi(attributes[2])
		C, _ := strconv.Atoi(attributes[3])
		// Append the attributes as a slice to the inputArray
		inputArray[i] = []int{S, R, H, C}
	}

	// Initialize a list to keep track of outdated items
	outdated := make([][]int, 0)

	// Compare each item with every other item to find outdated ones
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			// Check if item i is outdated compared to item j
			if inputArray[i][0] < inputArray[j][0] &&
				inputArray[i][1] < inputArray[j][1] &&
				inputArray[i][2] < inputArray[j][2] {
				// If outdated, add item i to the outdated list
				outdated = append(outdated, inputArray[i])
			}
		}
	}

	// Convert the outdated list to a set to remove duplicates
	outdatedSet := make(map[string]bool)
	for _, item := range outdated {
		outdatedSet[fmt.Sprintf("%v", item)] = true
	}

	// Initialize variables to track the minimum cost and corresponding item index
	minCost := 100000
	inputNumber := 0

	// Loop through the input items to find the one with the minimum cost that is not outdated
	for i := 0; i < n; i++ {
		currentItem := inputArray[i]
		cost := currentItem[3]  // Get the cost of the current item
		// Check if the current item is not outdated and has a lower cost than the current minimum
		if!outdatedSet[fmt.Sprintf("%v", currentItem)] && cost < minCost {
			minCost = currentItem[3]  // Update the minimum cost
			inputNumber = i + 1  // Store the index of the current item (1-based index)
		}
	}

	// Print the index of the item with the minimum cost that is not outdated
	fmt.Println(inputNumber)
}

func readLine(reader *bufio.Reader) string {
	line, _, err := reader.ReadLine()
	if err!= nil {
		panic(err)
	}
	return string(line)
}

