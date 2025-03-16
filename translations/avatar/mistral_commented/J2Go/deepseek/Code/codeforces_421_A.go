package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Initialize a Scanner object to read input
	scanner := bufio.NewScanner(os.Stdin)

	// Declare and initialize variables
	var n, a, b int

	// Read the number of test cases
	scanner.Scan()
	n, _ = strconv.Atoi(scanner.Text())

	// Read the number of elements in the first list
	scanner.Scan()
	a, _ = strconv.Atoi(scanner.Text())

	// Read the number of elements in the second list
	scanner.Scan()
	b, _ = strconv.Atoi(scanner.Text())

	// Create slices to store the lists
	list1 := make([]int, a)
	list2 := make([]int, b)

	// Read and store the elements of the first and second lists
	for i := 0; i < a; i++ {
		scanner.Scan()
		list1[i], _ = strconv.Atoi(scanner.Text())
	}
	for i := 0; i < b; i++ {
		scanner.Scan()
		list2[i], _ = strconv.Atoi(scanner.Text())
	}

	// Iterate through the input array and print the corresponding number based on the presence of the element in list1
	for i := 0; i < n; i++ {
		if contains(list1, i+1) { // Check if the current input element is present in list1
			fmt.Print(1, " ") // If present, print 1
		} else {
			fmt.Print(2, " ") // If not present, print 2
		}
	}

	// Close the Scanner object
	scanner.Scan() // Consume the remaining input
}

// Helper function to check if an element is present in a slice
func contains(slice []int, item int) bool {
	for _, value := range slice {
		if value == item {
			return true
		}
	}
	return false
}

