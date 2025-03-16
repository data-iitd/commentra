package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	// Read the number of items from user input
	n, _ := strconv.Atoi(readLine(reader))

	// Initialize an empty list to store the input items
	var inputArray [][]int

	// Loop to read each item's attributes (S, R, H, C)
	for i := 0; i < n; i++ {
		// Read the attributes S, R, H, C and convert them to integers
		attributes := readLine(reader)
		parts := strings.Split(attributes, " ")
		S, _ := strconv.Atoi(parts[0])
		R, _ := strconv.Atoi(parts[1])
		H, _ := strconv.Atoi(parts[2])
		C, _ := strconv.Atoi(parts[3])

		// Append the attributes as a slice to the inputArray
		inputArray = append(inputArray, []int{S, R, H, C})
	}

	// Initialize a map to keep track of outdated items
	outdated := make(map[string]bool)

	// Compare each item with every other item to find outdated ones
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			// Check if item i is outdated compared to item j
			if inputArray[i][0] < inputArray[j][0] &&
				inputArray[i][1] < inputArray[j][1] &&
				inputArray[i][2] < inputArray[j][2] {
				// If outdated, add item i to the outdated map
				outdated[fmt.Sprintf("%d,%d,%d,%d", inputArray[i][0], inputArray[i][1], inputArray[i][2], inputArray[i][3])] = true
			}
		}
	}

	// Initialize variables to track the minimum cost and corresponding item index
	minimumCost := 100000
	inputNumber := 0

	// Loop through the input items to find the one with the minimum cost that is not outdated
	for i := 0; i < n; i++ {
		currentItem := inputArray[i]
		cost := currentItem[3]  // Get the cost of the current item
		// Check if the current item is not outdated and has a lower cost than the current minimum
		if !outdated[fmt.Sprintf("%d,%d,%d,%d", currentItem[0], currentItem[1], currentItem[2], currentItem[3])] && cost < minimumCost {
			minimumCost = cost  // Update the minimum cost
			inputNumber = i + 1  // Store the index of the current item (1-based index)
		}
	}

	// Print the index of the item with the minimum cost that is not outdated
	fmt.Println(inputNumber)
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err != nil {
		panic(err)
	}
	return strings.TrimRight(string(str), "\r\n")
}
