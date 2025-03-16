package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	// Read input number of balls and number of events
	var N, M int
	fmt.Fscan(reader, &N, &M)

	// Initialize list of balls with their weight and position
	balls := make([][2]int, N)
	balls[0] = [2]int{0, 1}

	// Process each event
	for i := 0; i < M; i++ {
		// Read x and y coordinates of the event
		var x, y int
		fmt.Fscan(reader, &x, &y)

		// Get weight and position of balls at x and y
		w_x, r_x := balls[x-1][0], balls[x-1][1]
		w_y, r_y := balls[y-1][0], balls[y-1][1]

		// Update balls' weights and positions based on the event
		if w_x >= 1 && r_x >= 1 {
			// Ball x collides with ball y
			balls[x-1][0] -= 1
			balls[y-1][1] += 1
		} else if w_x == 0 {
			// Ball x is stationary and ball y collides with another ball
			balls[x-1][1] -= 1
			balls[y-1][1] += 1
		} else {
			// Ball x is moving and collides with ball y
			balls[x-1][0] -= 1
			balls[y-1][0] += 1
		}
	}

	// Calculate answer
	ans := 0
	// Iterate through the list of balls and count the number of moving balls
	for i := 0; i < N; i++ {
		if balls[i][1] > 0 {
			ans += 1
		}
	}

	// Print the answer
	fmt.Fprintln(writer, ans)
}
