package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// canTake checks if the resources are sufficient to meet the requirements
func canTake(xNeeded, xAvailable, yNeeded, yAvailable int) bool {
	if xNeeded > xAvailable {
		return false
	}
	if yNeeded > yAvailable {
		return false
	}
	return true
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	parts := strings.Split(strings.TrimSpace(input), " ")
	x, _ := strconv.Atoi(parts[0])
	y, _ := strconv.Atoi(parts[1])
	turn := 0

	// The main loop where the game alternates between two players based on the turn counter
	for {
		if turn%2 == 0 {
			// Hanako's turn actions: Attempt to take resources in the given order
			if canTake(2, x, 2, y) {
				x -= 2
				y -= 2
			} else if canTake(1, x, 12, y) {
				x -= 1
				y -= 12
			} else if canTake(0, x, 22, y) {
				y -= 22
			} else {
				fmt.Println("Hanako")
				return
			}
		} else {
			// Ciel's turn actions: Attempt to take resources in the given order
			if canTake(0, x, 22, y) {
				y -= 22
			} else if canTake(1, x, 12, y) {
				x -= 1
				y -= 12
			} else if canTake(2, x, 2, y) {
				x -= 2
				y -= 2
			} else {
				fmt.Println("Ciel")
				return
			}
		}
		turn++
	}
}
