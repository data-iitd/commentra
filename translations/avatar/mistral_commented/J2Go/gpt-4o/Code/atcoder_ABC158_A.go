package main

import (
	"fmt"
	"os"
	"strings"
)

func main() {
	// Create an instance of the solver and call the solve method
	solver := AStationAndBus{}
	solver.solve()
}

type AStationAndBus struct {
	// Struct to solve the problem
}

func (solver AStationAndBus) solve() {
	var s string
	// Read input from standard input
	fmt.Scan(&s)

	// Check if the string contains both 'A' and 'B'
	if strings.Contains(s, "A") && strings.Contains(s, "B") {
		fmt.Println("Yes") // Print "Yes" if both characters are present
	} else {
		fmt.Println("No") // Print "No" if either character is missing
	}
}

// <END-OF-CODE>
