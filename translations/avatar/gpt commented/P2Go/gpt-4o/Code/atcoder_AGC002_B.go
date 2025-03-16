package main

import (
	"fmt"
)

func main() {
	var N, M int
	fmt.Scan(&N, &M)

	// Initialize a slice to represent the state of each ball (weight and radius)
	balls := make([][2]int, N)
	for i := range balls {
		balls[i] = [2]int{1, 0} // Set initial weight to 1 and radius to 0
	}
	balls[0] = [2]int{0, 1} // Set the first ball's state

	// Process each operation
	for i := 0; i < M; i++ {
		var x, y int
		fmt.Scan(&x, &y) // Read the indices of the balls to operate on
		wX, rX := balls[x-1][0], balls[x-1][1] // Get the state of ball x
		wY, rY := balls[y-1][0], balls[y-1][1] // Get the state of ball y

		// Update the states of the balls based on their weights and radii
		if wX >= 1 && rX >= 1 {
			balls[x-1][0]-- // Decrease weight of ball x
			balls[y-1][1]++ // Increase radius of ball y
		} else if wX == 0 {
			balls[x-1][1]-- // Decrease radius of ball x
			balls[y-1][1]++ // Increase radius of ball y
		} else {
			balls[x-1][0]-- // Decrease weight of ball x
			balls[y-1][0]++ // Increase weight of ball y
		}
	}

	// Calculate the number of balls with a non-zero radius
	ans := 0
	for i := 0; i < N; i++ {
		if balls[i][1] > 0 { // Check if the radius of the ball is non-zero
			ans++ // Increment the count of balls with non-zero radius
		}
	}

	// Print the final count of balls with non-zero radius
	fmt.Println(ans)
}

// <END-OF-CODE>
