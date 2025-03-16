package main

import (
	"fmt"
	"sort"
	"strconv"
	"strings"
)

func s() {
	// Read input as a single line
	var input string
	fmt.Scanln(&input)

	// Split the input string into a slice of strings and convert to a slice of integers
	stringSlice := strings.Split(input, " ")
	var inputList []int
	for _, str := range stringSlice {
		num, _ := strconv.Atoi(str)
		inputList = append(inputList, num)
	}

	// Sort the input list in ascending order
	sort.Ints(inputList)

	// Initialize a variable to store the result
	result := ""

	// Iterate through the sorted list starting from the second element
	for i := 1; i < len(inputList); i++ {
		currentElement := inputList[i]
		previousElement := inputList[i-1]

		// Check if the current element is less than twice the previous element
		// and if it is not equal to the previous element
		if currentElement < previousElement*2 && currentElement != previousElement {
			// If the condition is true, set the result to 'YES'
			result = "YES"
			break
		}
	}

	// If result is still empty, set it to 'NO'
	if result == "" {
		result = "NO"
	}

	// Print the result
	fmt.Println(result)
}

// Main function to call s
func main() {
	s()
}
