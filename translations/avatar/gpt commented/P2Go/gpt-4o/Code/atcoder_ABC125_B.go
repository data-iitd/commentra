package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	// Read the number of elements
	var N int
	fmt.Scan(&N)

	// Read the values into a slice and convert them to integers
	var V []int
	var input string
	fmt.Scan(&input)
	for _, s := range strings.Split(input, " ") {
		val, _ := strconv.Atoi(s)
		V = append(V, val)
	}

	// Read the costs into a slice and convert them to integers
	var C []int
	fmt.Scan(&input)
	for _, s := range strings.Split(input, " ") {
		cost, _ := strconv.Atoi(s)
		C = append(C, cost)
	}

	// Initialize a variable to hold the total profit
	ans := 0

	// Iterate through each item
	for i := 0; i < N; i++ {
		// Check if the value is greater than the cost
		if V[i]-C[i] > 0 {
			// Calculate the profit and add it to the total profit
			ans += V[i] - C[i]
		}
	}

	// Print the total profit
	fmt.Println(ans)
}

// <END-OF-CODE>
