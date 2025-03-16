
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a scanner to read input from the user
	scan := bufio.NewScanner(os.Stdin)
	
	// Initialize variables for coordinates and control flags
	var i, j, x, y, k int
	var flag bool
	var dx, dy int
	var s string
	var ch []rune
	var co [][]int
	
	// Read the input string from the user
	scan.Scan()
	s = scan.Text()
	
	// Convert the input string to a rune array
	ch = []rune(s)
	
	// Create a 2D array to store coordinates
	co = make([][]int, 2)
	for i = 0; i < 2; i++ {
		co[i] = make([]int, 101)
	}
	
	// Store the initial coordinates (0, 0) in the coordinates array
	co[0][k] = x
	co[1][k] = y
	k++ // Increment the index for the next coordinate
	
	// Process each character in the input string to update coordinates
	for i = 0; i < len(s); i++ {
		switch ch[i] {
		case 'L': // Move left
			x--
		case 'R': // Move right
			x++
		case 'U': // Move up
			y++
		case 'D': // Move down
			y--
		}
		// Store the updated coordinates in the array
		co[0][k] = x
		co[1][k] = y
		k++ // Increment the index for the next coordinate
	}
	
	// Check for any bugs in the movement path
	for i = 0; i < k-3; i++ {
		for j = i + 3; j < k; j++ {
			// Calculate the differences in x and y coordinates
			dx = co[0][i] - co[0][j]
			dy = co[1][i] - co[1][j]
			
			// Make differences positive
			if dx < 0 {
				dx *= -1
			}
			if dy < 0 {
				dy *= -1
			}
			
			// Check if the two points are too close to each other
			if (dx <= 1 && dy == 0) || (dy <= 1 && dx == 0) {
				flag = false // Set flag to false if a bug is found
				break // Exit the inner loop
			}
		}
		if!flag {
			break // Exit the outer loop if a bug is found
		}
	}
	
	// Output the result based on the flag status
	if flag {
		fmt.Println("OK") // No bugs found
	} else {
		fmt.Println("BUG") // Bugs found in the movement path
	}
}
