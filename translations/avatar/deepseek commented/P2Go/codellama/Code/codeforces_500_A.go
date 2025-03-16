
package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the number of cells (n) and the target cell (t)
	n, t := readInts()

	// Read the list of cells that can be jumped from each cell
	s := readInts()

	// Initialize the current cell to 0
	currentCell := 0

	// Loop until the current cell exceeds the target cell
	for currentCell <= t {
		// Update the current cell by adding the value of the cell it's currently on
		currentCell += s[currentCell-1]

		// Check if the current cell is the target cell
		if currentCell == t {
			// If yes, print "YES" and exit the program
			fmt.Println("YES")
			os.Exit(0)
		} else {
			// If not, continue to the next iteration
			continue
		}
	}

	// If the loop finishes without finding the target cell, print "NO"
	fmt.Println("NO")
}

func readInts() (n, t int) {
	// Read the input
	input := readString()

	// Split the input into two parts
	parts := strings.Split(input, " ")

	// Convert the first part to an integer
	n, _ = strconv.Atoi(parts[0])

	// Convert the second part to an integer
	t, _ = strconv.Atoi(parts[1])

	// Return the two integers
	return n, t
}

func readString() string {
	// Read the input
	var input string
	fmt.Scanln(&input)

	// Return the input
	return input
}

// 