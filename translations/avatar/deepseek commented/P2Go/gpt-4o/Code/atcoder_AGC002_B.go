package main

import (
	"fmt"
)

func main() {
	var N, M int
	fmt.Scan(&N, &M)

	// Initializing the list of balls with pairs [white pieces, red pieces]
	balls := make([][2]int, N)
	for i := 0; i < N; i++ {
		balls[i] = [2]int{1, 0} // Each ball starts with 1 white piece and 0 red pieces
	}
	balls[0] = [2]int{0, 1} // Special initialization for the first ball

	// Loop to process each operation
	for i := 0; i < M; i++ {
		var x, y int
		fmt.Scan(&x, &y) // Reading the indices of the balls to be swapped
		wX, rX := balls[x-1][0], balls[x-1][1] // Extracting the current state of ball x
		wY, rY := balls[y-1][0], balls[y-1][1] // Extracting the current state of ball y

		// Swapping the balls if possible
		if wX >= 1 && rX >= 1 {
			balls[x-1][0]--
			balls[y-1][1]++
		} else if wX == 0 {
			balls[x-1][1]--
			balls[y-1][1]++
		} else {
			balls[x-1][0]--
			balls[y-1][0]++
		}
	}

	// Counting the number of balls with at least one red or white piece
	ans := 0
	for i := 0; i < N; i++ {
		if balls[i][1] > 0 {
			ans++
		}
	}

	// Printing the final count
	fmt.Println(ans)
}

// <END-OF-CODE>
