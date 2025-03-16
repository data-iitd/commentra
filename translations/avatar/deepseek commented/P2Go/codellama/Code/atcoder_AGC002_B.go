
package main

import (
	"fmt"
	"math"
	"strconv"
	"strings"
)

func main() {
	// Reading the number of balls (N) and the number of operations (M)
	var N, M int
	fmt.Scan(&N, &M)

	// Initializing the list of balls with pairs [white pieces, red pieces]
	balls := make([][]int, N)
	for i := 0; i < N; i++ {
		balls[i] = make([]int, 2)
		balls[i][0] = 1
		balls[i][1] = 0
	}

	// Special initialization for the first ball
	balls[0][0] = 0
	balls[0][1] = 1

	// Loop to process each operation
	for i := 0; i < M; i++ {
		// Reading the indices of the balls to be swapped
		var x, y int
		fmt.Scan(&x, &y)

		// Extracting the current state of ball x
		w_x := balls[x-1][0]
		r_x := balls[x-1][1]

		// Extracting the current state of ball y
		w_y := balls[y-1][0]
		r_y := balls[y-1][1]

		// Swapping the balls if possible
		if w_x >= 1 && r_x >= 1 {
			balls[x-1][0] -= 1
			balls[y-1][1] += 1
		} else if w_x == 0 {
			balls[x-1][1] -= 1
			balls[y-1][1] += 1
		} else {
			balls[x-1][0] -= 1
			balls[y-1][0] += 1
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

