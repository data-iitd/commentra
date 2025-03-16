
package main

import (
	"fmt"
	"math"
)

func main() {
	// Read the number of balls (N) and the number of operations (M)
	var N, M int
	fmt.Scan(&N, &M)

	// Initialize a list to represent the state of each ball (weight and radius)
	balls := make([][]int, N)
	for i := range balls {
		balls[i] = make([]int, 2)
	}
	balls[0][1] = 1  // Set the first ball's state

	// Process each operation
	for i := 0; i < M; i++ {
		// Read the indices of the balls to operate on
		var x, y int
		fmt.Scan(&x, &y)
		w_x, r_x := balls[x-1][0], balls[x-1][1]  // Get the state of ball x
		w_y, r_y := balls[y-1][0], balls[y-1][1]  // Get the state of ball y

		// Update the states of the balls based on their weights and radii
		if w_x >= 1 && r_x >= 1 {
			balls[x-1][0] -= 1  // Decrease weight of ball x
			balls[y-1][1] += 1  // Increase radius of ball y
		} else if w_x == 0 {
			balls[x-1][1] -= 1  // Decrease radius of ball x
			balls[y-1][1] += 1  // Increase radius of ball y
		} else {
			balls[x-1][0] -= 1  // Decrease weight of ball x
			balls[y-1][0] += 1  // Increase weight of ball y
		}
	}

	// Calculate the number of balls with a non-zero radius
	ans := 0
	for i := range balls {
		if balls[i][1] != 0 {  // Check if the radius of the ball is non-zero
			ans++  // Increment the count of balls with non-zero radius
		}
	}

	// Print the final count of balls with non-zero radius
	fmt.Println(ans)
}

