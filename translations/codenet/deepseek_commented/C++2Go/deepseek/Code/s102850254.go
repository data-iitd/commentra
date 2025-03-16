package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

var d int // Number of test cases
var mapGrid [105]string // Map to store the grid
var n int // Size of the map

// Function to process the map
func visit() {
	dx := [4]int{0, 1, 0, -1} // Direction vectors for x-axis
	dy := [4]int{-1, 0, 1, 0} // Direction vectors for y-axis
	var sum, flg int = 0, 0 // Variables to track the sum of steps and the direction flag
	var x, y int = 2, n // Starting position (2, n)
	mapGrid[y] = mapGrid[y][:x] + " " + mapGrid[y][x+1:] // Mark the starting position as visited
	var ab [4]int = [4]int{2, 2, 2, 2} // Array to store the previous steps

	// Main loop to process the map
	for {
		sum = 0
		for {
			if mapGrid[y + dy[flg] * 2][x + dx[flg] * 2] != '#' && mapGrid[y + dy[flg]][x + dx[flg]] != ' ' {
				flg++
				break
			}
			mapGrid[y + dy[flg]] = mapGrid[y + dy[flg]][:x + dx[flg]] + " " + mapGrid[y + dy[flg]][x + dx[flg]+1:] // Mark the current position as visited
			y += dy[flg] // Update the y-coordinate
			x += dx[flg] // Update the x-coordinate
			sum++ // Increment the step count
		}
		if flg == 4 { flg = 0 } // Reset the flag if it reaches 4
		if sum == 0 { break } // Break the loop if no steps are taken
		ab[0], ab[1], ab[2] = ab[1], ab[2], sum // Update the array with the previous steps
		if ab[0] == 1 && ab[2] == 1 && ab[1] == 1 { break } // Break the loop if the pattern repeats
	}
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	fmt.Sscan(scanner.Text(), &d) // Read the number of test cases

	for l := 0; l < d; l++ {
		scanner.Scan()
		fmt.Sscan(scanner.Text(), &n) // Read the size of the map

		if n == 1 {
			fmt.Println("#") // Print a single '#' if the size is 1
			if l != d - 1 { fmt.Println() } // Add a newline between test cases
			continue
		}

		// Initialize the map with borders and fill it with '#' and '.'
		for i := 0; i <= n + 1; i++ {
			mapGrid[i] = strings.Repeat("#", n + 2)
			for j := 0; j <= n + 1; j++ {
				if i == 0 || j == 0 || i == n + 1 || j == n + 1 {
					mapGrid[i] = mapGrid[i][:j] + "." + mapGrid[i][j+1:]
				}
			}
		}

		visit() // Call the visit function to process the map

		// Print the processed map
		for i := 1; i <= n; i++ {
			fmt.Println(mapGrid[i][1:n+1])
		}
		if l != d - 1 { fmt.Println() } // Add a newline between test cases
	}
}

