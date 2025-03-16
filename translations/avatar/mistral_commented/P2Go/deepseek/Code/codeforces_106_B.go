package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	// Read the number of items
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())

	// Initialize an empty list to store the input data
	var inputArray [][]int

	// Read n items from the standard input and append them to the input_array
	for i := 0; i < n; i++ {
		scanner.Scan()
		S, _ := strconv.Atoi(scanner.Text())
		scanner.Scan()
		R, _ := strconv.Atoi(scanner.Text())
		scanner.Scan()
		H, _ := strconv.Atoi(scanner.Text())
		scanner.Scan()
		C, _ := strconv.Atoi(scanner.Text())
		inputArray = append(inputArray, []int{S, R, H, C})
	}

	// Initialize an empty list to store the outdated items
	var outdated [][]int

	// Check for outdated items in the input array
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			// Check if the current item is older and smaller than the next one
			if (inputArray[i][0] < inputArray[j][0] &&
				inputArray[i][1] < inputArray[j][1] &&
				inputArray[i][2] < inputArray[j][2]) {
				// Append the current item to the outdated list
				outdated = append(outdated, inputArray[i])
			}
		}
	}

	// Convert the outdated list to a set to remove duplicates
	outdatedSet := make(map[[4]int]bool)
	for _, item := range outdated {
		outdatedSet[[4]int{item[0], item[1], item[2], item[3]}] = true
	}

	// Initialize minimum_cost and input_number to large initial values
	minimum_cost := 100000
	input_number := 0

	// Find the item with the minimum cost that is not outdated
	for i := 0; i < n; i++ {
		current_item := inputArray[i]
		cost := current_item[3]
		// Check if the current item is not outdated and has a smaller cost than minimum_cost
		if _, exists := outdatedSet[[4]int{current_item[0], current_item[1], current_item[2], current_item[3]}]
		if cost < minimum_cost {
			// Update minimum_cost and input_number
			minimum_cost = cost
			input_number = i + 1
		}
	}

	// Print the index of the item with the minimum cost that is not outdated
	fmt.Println(input_number)
}
