package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Method to check if the required resources can be taken
func canTake(xNeeded, xAvailable, yNeeded, yAvailable int) bool {
	// Check if the needed x resources are greater than available
	if xNeeded > xAvailable {
		return false
	}
	// Check if the needed y resources are greater than available
	if yNeeded > yAvailable {
		return false
	}
	// If both checks pass, return true
	return true
}

func main() {
	// Initialize bufio.Reader to read input
	reader := bufio.NewReader(os.Stdin)
	// Read the input line to extract x and y values
	input, _ := reader.ReadString('\n')
	values := strings.Split(strings.TrimSpace(input), " ")
	x, _ := strconv.Atoi(values[0]) // Parse x value
	y, _ := strconv.Atoi(values[1]) // Parse y value
	turn := 0 // Initialize turn counter

	// Infinite loop to alternate turns between two players
	for {
		// Check if it's the first player's turn (even turn number)
		if turn%2 == 0 {
			// Try to take resources according to the defined rules
			if canTake(2, x, 2, y) {
				x -= 2 // Deduct resources for the first option
				y -= 2
			} else if canTake(1, x, 12, y) {
				x -= 1 // Deduct resources for the second option
				y -= 12
			} else if canTake(0, x, 22, y) {
				y -= 22 // Deduct resources for the third option
			} else {
				// If no options are available, first player loses
				fmt.Println("Hanako")
				return
			}
		} else {
			// Check if it's the second player's turn (odd turn number)
			if canTake(0, x, 22, y) {
				y -= 22 // Deduct resources for the first option
			} else if canTake(1, x, 12, y) {
				x -= 1 // Deduct resources for the second option
				y -= 12
			} else if canTake(2, x, 2, y) {
				x -= 2 // Deduct resources for the third option
				y -= 2
			} else {
				// If no options are available, second player loses
				fmt.Println("Ciel")
				return
			}
		}
		turn++ // Increment turn counter for the next iteration
	}
}

