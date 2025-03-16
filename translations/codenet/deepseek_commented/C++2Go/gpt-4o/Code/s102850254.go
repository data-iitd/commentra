package main

import (
	"fmt"
)

var d int // Number of test cases
var n int // Size of the map
var grid [105]string // Map to store the grid

// Function to process the map
func visit() {
	dx := [4]int{0, 1, 0, -1} // Direction vectors for x-axis
	dy := [4]int{-1, 0, 1, 0} // Direction vectors for y-axis
	var sum, flg int // Variables to track the sum of steps and the direction flag
	x, y := 2, n // Starting position (2, n)
	grid[y] = replaceAt(grid[y], x, ' ') // Mark the starting position as visited
	ab := [4]int{2, 2, 2, 2} // Array to store the previous steps

	// Main loop to process the map
	for {
		sum = 0
		for {
			if grid[y+dy[flg]*2][x+dx[flg]*2] != '#' && grid[y+dy[flg]][x+dx[flg]] != ' ' {
				flg++
				break
			}
			grid[y+dy[flg]] = replaceAt(grid[y+dy[flg]], x+dx[flg], ' ') // Mark the current position as visited
			y += dy[flg] // Update the y-coordinate
			x += dx[flg] // Update the x-coordinate
			sum++ // Increment the step count
		}
		if flg == 4 {
			flg = 0 // Reset the flag if it reaches 4
		}
		if sum == 0 {
			break // Break the loop if no steps are taken
		}
		ab[0] = ab[1] // Update the array with the previous steps
		ab[1] = ab[2]
		ab[2] = sum
		if ab[0] == 1 && ab[2] == 1 && ab[1] == 1 {
			break // Break the loop if the pattern repeats
		}
	}
}

// Helper function to replace a character at a specific index in a string
func replaceAt(s string, index int, replacement rune) string {
	runes := []rune(s)
	runes[index] = replacement
	return string(runes)
}

func main() {
	fmt.Scan(&d) // Read the number of test cases

	for l := 0; l < d; l++ {
		fmt.Scan(&n) // Read the size of the map

		if n == 1 {
			fmt.Println("#") // Print a single '#' if the size is 1
			if l != d-1 {
				fmt.Println() // Add a newline between test cases
			}
			continue
		}

		// Initialize the map with borders and fill it with '#' and '.'
		for i := 0; i <= n+1; i++ {
			grid[i] = string(make([]rune, n+2))
			for j := 0; j <= n+1; j++ {
				grid[i] = replaceAt(grid[i], j, '#')
				if i == 0 || j == 0 || i == n+1 || j == n+1 {
					grid[i] = replaceAt(grid[i], j, '.')
				}
			}
		}

		visit() // Call the visit function to process the map

		// Print the processed map
		for i := 1; i <= n; i++ {
			for j := 1; j < len(grid[i])-1; j++ {
				fmt.Print(string(grid[i][j]))
			}
			fmt.Println()
		}
		if l != d-1 {
			fmt.Println() // Add a newline between test cases
		}
	}
}

// <END-OF-CODE>
