package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Create a Scanner object to read input from the user
	scanner := bufio.NewScanner(os.Stdin)
	
	// Initialize variables for coordinates and control flags
	var i, j, x, y, k int
	var flag bool
	
	// Declare variables for input string and character array
	var s string
	var ch []rune
	
	// Create a 2D slice to store coordinates
	var co [][]int
	
	// Read the input string from the user
	scanner.Scan()
	s = scanner.Text()
	
	// Convert the input string to a character array
	ch = []rune(s)
	
	// Store the initial coordinates (0, 0) in the coordinates slice
	co = append(co, []int{x, y})
	k++ // Increment the index for the next coordinate
	
	// Process each character in the input string to update coordinates
	for i = 0; i < len(ch); i++ {
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
		// Store the updated coordinates in the slice
		co = append(co, []int{x, y})
		k++ // Increment the index for the next coordinate
	}
	
	// Check for any bugs in the movement path
	flag = true
	for i = 0; i < k - 3; i++ {
		for j = i + 3; j < k; j++ {
			// Calculate the differences in x and y coordinates
			dx := co[i][0] - co[j][0]
			dy := co[i][1] - co[j][1]
			
			// Make differences positive
			if dx < 0 {
				dx = -dx
			}
			if dy < 0 {
				dy = -dy
			}
			
			// Check if the two points are too close to each other
			if (dx <= 1 && dy == 0) || (dy <= 1 && dx == 0) {
				flag = false // Set flag to false if a bug is found
				break // Exit the inner loop
			}
		}
		if !flag {
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
