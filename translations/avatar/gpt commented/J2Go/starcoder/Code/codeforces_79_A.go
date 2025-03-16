package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

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
	// Initialize BufferedReader to read input
	reader := bufio.NewReader(os.Stdin)
	// Tokenize the input line to extract x and y values
	input, _ := reader.ReadString('\n')
	input = strings.TrimSuffix(input, "\n")
	input = strings.TrimPrefix(input, "x ")
	input = strings.TrimSuffix(input, " y")
	x, _ := strconv.Atoi(input)
	input, _ = reader.ReadString('\n')
	input = strings.TrimSuffix(input, "\n")
	y, _ := strconv.Atoi(input)
	turn := 0
	// Infinite loop to alternate turns between two players
	for {
		// Check if it's the first player's turn (even turn number)
		if turn%2 == 0 {
			// Try to take resources according to the defined rules
			if canTake(2, x, 2, y) {
				x -= 2
				y -= 2
			} else if canTake(1, x, 12, y) {
				x -= 1
				y -= 12
			} else if canTake(0, x, 22, y) {
				y -= 22
			} else {
				// If no options are available, first player loses
				fmt.Println("Hanako")
				return
			}
		} else {
			// Check if it's the second player's turn (odd turn number)
			if canTake(0, x, 22, y) {
				y -= 22
			} else if canTake(1, x, 12, y) {
				x -= 1
				y -= 12
			} else if canTake(2, x, 2, y) {
				x -= 2
				y -= 2
			} else {
				// If no options are available, second player loses
				fmt.Println("Ciel")
				return
			}
		}
		turn++
	}
}

