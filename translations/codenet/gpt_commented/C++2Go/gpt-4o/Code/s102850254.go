package main

import (
	"fmt"
)

// Global variables
var d int // Number of test cases
var n int // Size of the map
var m [][]rune // 2D map representation

// Function to visit and modify the map based on certain conditions
func visit() {
	// Direction vectors for moving in 4 possible directions (up, right, down, left)
	dx := []int{0, 1, 0, -1}
	dy := []int{-1, 0, 1, 0}
	sum, flg := 0, 0 // Initialize sum and flag for direction
	x, y := 2, n    // Starting position on the map
	m[y][x] = ' '   // Mark the starting position as visited
	ab := [4]int{2, 2, 2, 2} // Array to track the last three sums

	// Infinite loop to traverse the map
	for {
		sum = 0 // Reset sum for the current direction
		for {
			// Check if the next position is valid (not a wall and not already visited)
			if m[y+dy[flg]*2][x+dx[flg]*2] != '#' && m[y+dy[flg]][x+dx[flg]] != ' ' {
				flg++ // Change direction
				break // Exit the inner loop
			}

			// Mark the current position as visited
			m[y+dy[flg]][x+dx[flg]] = ' '
			// Move to the next position
			y += dy[flg]
			x += dx[flg]
			sum++ // Increment the sum of visited positions
		}
		// Reset direction if all 4 directions have been tried
		if flg == 4 {
			flg = 0
		}
		// Break the loop if no positions were visited in this direction
		if sum == 0 {
			break
		}
		// Update the history of sums
		ab[0], ab[1], ab[2] = ab[1], ab[2], sum
		// Break if the last three sums are all 1 (indicating a dead end)
		if ab[0] == 1 && ab[1] == 1 && ab[2] == 1 {
			break
		}
	}
}

// Main function
func main() {
	// Read the number of test cases
	fmt.Scan(&d)

	// Loop through each test case
	for l := 0; l < d; l++ {
		// Read the size of the map
		fmt.Scan(&n)

		// Handle the case where the map size is 1
		if n == 1 {
			fmt.Println("#") // Output a single wall
			if l != d-1 {
				fmt.Println() // Print a newline if not the last test case
			}
			continue // Skip to the next test case
		}

		// Initialize the map with walls and empty spaces
		m = make([][]rune, n+2)
		for i := range m {
			m[i] = make([]rune, n+2) // Resize the row to accommodate walls
			for j := range m[i] {
				m[i][j] = '#' // Fill the map with walls
				// Set the border of the map to empty spaces
				if i == 0 || j == 0 || i == n+1 || j == n+1 {
					m[i][j] = '.'
				}
			}
		}

		// Call the visit function to modify the map
		visit()

		// Output the modified map
		for i := 1; i <= n; i++ {
			for j := 1; j < len(m[i])-1; j++ {
				fmt.Print(string(m[i][j])) // Print each row of the map
			}
			fmt.Println() // Newline after each row
		}
		// Print a newline between test cases if not the last one
		if l != d-1 {
			fmt.Println()
		}
	}
}

// <END-OF-CODE>
