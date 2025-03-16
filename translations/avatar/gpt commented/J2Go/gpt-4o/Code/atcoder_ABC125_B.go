package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	// Read the number of items (n) from the input
	var n int
	fmt.Scanln(&n)

	// Read the values (vStr) from the input and convert to a map
	var vStr string
	fmt.Scanln(&vStr)
	vList := str2List(vStr)

	// Read the costs (cStr) from the input and convert to a map
	var cStr string
	fmt.Scanln(&cStr)
	cList := str2List(cStr)

	// Initialize a variable to keep track of the maximum profit
	max := 0

	// Calculate the profit for each item and sum up the positive profits
	for i := 0; i < n; i++ {
		profit := vList[i] - cList[i]
		// Only add to max if the profit is positive
		if profit > 0 {
			max += profit
		}
	}

	// Output the total maximum profit
	fmt.Println(max)
}

// Helper function to convert a space-separated string of integers into a map
func str2List(str string) map[int]int {
	// Split the input string into an array of strings
	vArrStr := strings.Split(str, " ")

	// Create a map to hold the integer values with their corresponding indices
	ret := make(map[int]int)

	// Populate the map with values from the array
	for key, val := range vArrStr {
		num, _ := strconv.Atoi(val)
		ret[key] = num
	}

	// Return the populated map
	return ret
}

// <END-OF-CODE>
