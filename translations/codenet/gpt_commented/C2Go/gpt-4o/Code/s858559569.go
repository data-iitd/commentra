package main

import (
	"fmt"
)

const N = 4

// Define a structure to represent the puzzle state
type Pazz struct {
	P [N][N]int // 2D array to hold the puzzle grid
}

var Q Pazz // Global variable to hold the current state of the puzzle
var dx = [4]int{0, 1, 0, -1} // Array to represent movement in the x-direction (right, down, left, up)
var dy = [4]int{1, 0, -1, 0} // Array to represent movement in the y-direction (right, down, left, up)

// Function to calculate the heuristic value (Manhattan distance) of the puzzle state
func Heu(Q Pazz) int {
	var sum int

	// Loop through each cell in the puzzle
	for i := 0; i < N; i++ {
		for j := 0; j < N; j++ {
			// Skip the empty tile (represented by 0)
			if Q.P[i][j] == 0 {
				continue
			}

			// Calculate the expected position of the tile
			hx := (Q.P[i][j] - 1) % N - j // Horizontal distance
			hy := (Q.P[i][j] - 1) / N - i // Vertical distance

			// Update the sum based on the distances
			if hx < 0 {
				sum -= hx
			} else {
				sum += hx
			}

			if hy < 0 {
				sum -= hy
			} else {
				sum += hy
			}
		}
	}
	return sum // Return the total heuristic value
}

// Depth-first search function to explore possible moves
func dfs(x, y, max, count, n int) int {
	var ans = -1

	// Calculate the heuristic value for the current state
	h := Heu(Q)

	// If the puzzle is solved (heuristic is 0), return the count of moves
	if h == 0 {
		return count
	}

	// If the current count plus heuristic exceeds the maximum allowed, return -1
	if (count + h) > max {
		return -1
	}

	// Explore all possible moves
	for i := 0; i < 4; i++ {
		x0 := x + dx[i] // Calculate new x position
		y0 := y + dy[i] // Calculate new y position

		// Check if the move is valid and not reversing the last move
		if (i == (n+2)%4 && n != -1) || !(0 <= x0 && x0 < N && 0 <= y0 && y0 < N) {
			continue
		}

		// Swap the empty tile with the adjacent tile
		Q.P[y][x], Q.P[y0][x0] = Q.P[y0][x0], Q.P[y][x]

		// Recursively call dfs with the new position
		ans = dfs(x0, y0, max, count+1, i)

		// If a solution is found, return the answer
		if ans != -1 {
			return ans
		}

		// Swap back to restore the previous state
		Q.P[y][x], Q.P[y0][x0] = Q.P[y0][x0], Q.P[y][x]
	}

	return -1 // Return -1 if no solution is found
}

// Main function to execute the program
func main() {
	var kx, ky, ans, a int

	// Read the puzzle input from the user
	for i := 0; i < N; i++ {
		for j := 0; j < N; j++ {
			fmt.Scan(&a) // Read each tile value
			Q.P[i][j] = a // Store the value in the puzzle state
			if a == 0 { // If the tile is empty
				kx = j // Store its x position
				ky = i // Store its y position
			}
		}
	}

	// Attempt to solve the puzzle with increasing maximum move limits
	for i := 1; i < 46; i++ {
		ans = dfs(kx, ky, i, 0, -1) // Call dfs to find a solution
		if ans != -1 { // If a solution is found
			fmt.Println(ans) // Print the number of moves
			break // Exit the loop
		}
	}
}

// <END-OF-CODE>
