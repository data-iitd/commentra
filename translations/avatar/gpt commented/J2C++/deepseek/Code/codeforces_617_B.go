package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Creating a new Scanner object for reading user input
	scanner := bufio.NewScanner(os.Stdin)

	// Reading an integer n from user input, which represents the number of elements
	scanner.Scan()
	n, _ := fmt.Sscan(scanner.Text(), &n)

	// Initializing a slice to store the indices of elements that are equal to 1
	var arr []int

	// Looping through the input values to find indices of elements equal to 1
	for i := 0; i < n; i++ {
		// Reading the next integer value from user input
		scanner.Scan()
		val := scanner.Text()
		if val == "1" {
			arr = append(arr, i)
		}
	}

	// Checking if the slice of indices is empty
	if len(arr) == 0 {
		// If the slice is empty, print 0
		fmt.Println(0)
	} else {
		// If the slice is not empty, initialize a result variable to 1
		result := 1

		// Calculate the product of the differences between consecutive indices
		for i := 1; i < len(arr); i++ {
			result *= arr[i] - arr[i-1]
		}

		// Print the final result
		fmt.Println(result)
	}
}
