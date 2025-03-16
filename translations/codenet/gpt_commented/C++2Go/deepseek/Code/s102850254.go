package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

// Global variables
var d int // Number of test cases
var map1 [105]string // 2D map representation
var n int // Size of the map

// Function to visit and modify the map based on certain conditions
func visit() {
	// Direction vectors for moving in 4 possible directions (up, right, down, left)
	dx := [4]int{0, 1, 0, -1}
	dy := [4]int{-1, 0, 1, 0}
	var sum, flg int // Initialize sum and flag for direction
	x, y := 2, n // Starting position on the map
	map1[y] = map1[y][:x] + " " + map1[y][x+1:] // Mark the starting position as visited
	ab := [3]int{2, 2, 2} // Array to track the last three sums

	// Infinite loop to traverse the map
	for {
		sum = 0 // Reset sum for the current direction
		for {
			// Check if the next position is valid (not a wall and not already visited)
			if map1[y+dy[flg]*2][x+dx[flg]*2] != '#' && map1[y+dy[flg]][x+dx[flg]] != ' ' {
				flg++ // Change direction
				break // Exit the inner loop
			}

			// Mark the current position as visited
			map1[y+dy[flg]] = map1[y+dy[flg]][:x+dx[flg]] + " " + map1[y+dy[flg]][x+dx[flg]+1:]
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
		if ab[0] == 1 && ab[2] == 1 && ab[1] == 1 {
			break
		}
	}
}

// Main function
func main() {
	// Read the number of test cases
	fmt.Scan(&d)

	// Create a new scanner for reading input
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

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
		for i := 0; i <= n+1; i++ {
			map1[i] = strings.Repeat("#", n+2) // Resize the row to accommodate walls
			// Set the border of the map to empty spaces
			if i == 0 || i == n+1 {
				map1[i] = strings.Repeat(".", n+2)
			} else {
				map1[i] = ".." + map1[i] + ".."
			}
		}

		// Call the visit function to modify the map
		visit()

		// Output the modified map
		for i := 1; i <= n; i++ {
			fmt.Println(map1[i][1 : len(map1[i])-1]) // Print each row of the map
		}
		// Print a newline between test cases if not the last one
		if l != d-1 {
			fmt.Println()
		}
	}
}

