package main

import (
	"fmt"
)

const INF = 1e9
const mod = 1e9 + 7

func main() {
	var N, M int
	fmt.Scan(&N, &M)

	// Initialize list of balls with their weight and position
	balls := make([][2]int, N)
	for i := range balls {
		balls[i] = [2]int{1, 0}
	}
	balls[0] = [2]int{0, 1}

	// Process each event
	for i := 0; i < M; i++ {
		var x, y int
		fmt.Scan(&x, &y)

		// Get weight and position of balls at x and y
		wX, rX := balls[x-1][0], balls[x-1][1]
		wY, rY := balls[y-1][0], balls[y-1][1]

		// Update balls' weights and positions based on the event
		if wX >= 1 && rX >= 1 {
			// Ball x collides with ball y
			balls[x-1][0]--
			balls[y-1][1]++
		} else if wX == 0 {
			// Ball x is stationary and ball y collides with another ball
			balls[x-1][1]--
			balls[y-1][1]++
		} else {
			// Ball x is moving and collides with ball y
			balls[x-1][0]--
			balls[y-1][0]++
		}
	}

	// Calculate answer
	ans := 0
	// Iterate through the list of balls and count the number of moving balls
	for i := 0; i < N; i++ {
		if balls[i][1] > 0 {
			ans++
		}
	}

	// Print the answer
	fmt.Println(ans)
}

// <END-OF-CODE>
