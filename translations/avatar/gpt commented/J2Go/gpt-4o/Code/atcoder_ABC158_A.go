package main

import (
	"fmt"
	"os"
	"strings"
)

func main() {
	// Create a scanner for reading input
	var input string
	fmt.Scan(&input)

	// Create an instance of the AStationAndBus struct to solve the problem
	solver := AStationAndBus{}

	// Call the solve method with the input string
	solver.solve(input)
}

// AStationAndBus struct to handle the logic of the problem
type AStationAndBus struct{}

// solve method to check for 'A' and 'B' in the input string
func (solver AStationAndBus) solve(s string) {
	// Check if the string contains both 'A' and 'B'
	if strings.Contains(s, "A") && strings.Contains(s, "B") {
		// If both characters are present, print "Yes"
		fmt.Println("Yes")
	} else {
		// If either character is missing, print "No"
		fmt.Println("No")
	}
}

// <END-OF-CODE>
