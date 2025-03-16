package main

import (
	"fmt"
	"sort"
	"strconv"
	"strings"
)

func main() {
	// Define a function named s that takes no arguments
	s()
}

func s() {
	// Read input as a list of integers
	var input string
	fmt.Scanln(&input)
	inputList := strings.Split(input, " ")
	var intList []int
	for _, str := range inputList {
		num, _ := strconv.Atoi(str)
		intList = append(intList, num)
	}

	// Sort the input list in ascending order
	sort.Ints(intList)

	// Initialize a variable to store the result
	result := "NO"

	// Iterate through the sorted list starting from the second element
	for i := 1; i < len(intList); i++ {
		// Compare the current element with the previous one
		currentElement := intList[i]
		previousElement := intList[i-1]

		// Check if the current element is less than twice the previous element
		// and if it is not equal to the previous element
		if currentElement < previousElement*2 && currentElement != previousElement {
			// If the condition is true, set the result to 'YES'
			result = "YES"
			// Break out of the loop since we have found the answer
			break
		}
	}

	// Print the result
	fmt.Println(result)
}

