package main

import (
	"fmt"
	"os"
)

func canTake(xNeeded, xAvailable, yNeeded, yAvailable int) bool {
	if xNeeded > xAvailable {
		return false // Check if xNeeded is more than xAvailable
	}
	if yNeeded > yAvailable {
		return false // Check if yNeeded is more than yAvailable
	}
	return true // Return true if both conditions are satisfied
}

func main() {
	var x, y int
	_, err := fmt.Scanf("%d %d", &x, &y) // Reading input values for x and y
	if err != nil {
		fmt.Println("Error reading input:", err)
		os.Exit(1)
	}

	turn := 0 // Initializing the turn counter

	// The main loop where the game alternates between two players based on the turn counter
	for {
		if turn%2 == 0 { // Check if it's Hanako's turn (even turn)
			// Hanako's turn actions: Attempt to take resources in the given order
			if canTake(2, x, 2, y) { // Attempt to take 2 from both x and y
				x -= 2
				y -= 2
			} else if canTake(1, x, 12, y) { // Attempt to take 1 from x and 12 from y
				x -= 1
				y -= 12
			} else if canTake(0, x, 22, y) { // Attempt to take 22 from y
				y -= 22
			} else { // If no resources can be taken, Hanako loses
				fmt.Println("Hanako")
				return
			}
		} else { // It's Ciel's turn (odd turn)
			// Ciel's turn actions: Attempt to take resources in the given order
			if canTake(0, x, 22, y) { // Attempt to take 22 from y
				y -= 22
			} else if canTake(1, x, 12, y) { // Attempt to take 1 from x and 12 from y
				x -= 1
				y -= 12
			} else if canTake(2, x, 2, y) { // Attempt to take 2 from both x and y
				x -= 2
				y -= 2
			} else { // If no resources can be taken, Ciel loses
				fmt.Println("Ciel")
				return
			}
		}
		turn++ // Increment the turn counter
	}
}

// <END-OF-CODE>
