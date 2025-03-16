package main

import (
	"fmt"
	"strings"
)

func visit(map [][]string, n int) {
	dx := []int{0, 1, 0, -1} // Direction vectors for x-axis
	dy := []int{-1, 0, 1, 0} // Direction vectors for y-axis
	sum, flg := 0, 0 // Variables to track the sum of steps and the direction flag
	x, y := 2, n // Starting position (2, n)
	map[y][x] = " " // Mark the starting position as visited
	ab := []int{2, 2, 2, 2} // Array to store the previous steps

	// Main loop to process the map
	for {
		sum = 0
		for {
			if map[y + dy[flg] * 2][x + dx[flg] * 2] != "#" && map[y + dy[flg]][x + dx[flg]] != " " {
				flg++
				break
			}
			map[y + dy[flg]][x + dx[flg]] = " " // Mark the current position as visited
			y = y + dy[flg] // Update the y-coordinate
			x = x + dx[flg] // Update the x-coordinate
			sum++ // Increment the step count
		}
		if flg == 4 {
			flg = 0
		} // Reset the flag if it reaches 4
		if sum == 0 {
			break
		} // Break the loop if no steps are taken
		ab[0] = ab[1] // Update the array with the previous steps
		ab[1] = ab[2]
		ab[2] = sum
		if ab[0] == 1 && ab[2] == 1 && ab[1] == 1 {
			break
		} // Break the loop if the pattern repeats
	}
}

func main() {
	var d int // Number of test cases
	fmt.Scan(&d) // Read the number of test cases

	for l := 0; l < d; l++ {
		var n int // Size of the map
		fmt.Scan(&n) // Read the size of the map

		if n == 1 {
			fmt.Println("#") // Print a single '#' if the size is 1
			if l != d - 1 {
				fmt.Println() // Add a newline between test cases
			}
			continue
		}

		// Initialize the map with borders and fill it with '#' and '.'
		map := make([][]string, n+2)
		for i := 0; i <= n+1; i++ {
			map[i] = make([]string, n+2)
			for j := 0; j <= n+1; j++ {
				map[i][j] = "#"
				if i == 0 || j == 0 || i == n+1 || j == n+1 {
					map[i][j] = "."
				}
			}
		}

		visit(map, n) // Call the visit function to process the map

		// Print the processed map
		for i := 1; i <= n; i++ {
			for j := 1; j < len(map[i])-1; j++ {
				fmt.Print(map[i][j])
			}
			fmt.Println()
		}
		if l != d-1 {
			fmt.Println() // Add a newline between test cases
		}
	}
}

