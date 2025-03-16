package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	// Read the number of cells (n) and the target cell (t) from input
	input, _ := reader.ReadString('\n')
	parts := strings.Split(strings.TrimSpace(input), " ")
	n, _ := strconv.Atoi(parts[0])
	t, _ := strconv.Atoi(parts[1])

	// Read the list of jumps for each cell
	input, _ = reader.ReadString('\n')
	jumps := []int{}
	for _, jump := range strings.Split(strings.TrimSpace(input), " ") {
		jumpVal, _ := strconv.Atoi(jump)
		jumps = append(jumps, jumpVal)
	}

	// Initialize the current cell position
	currentCell := 0

	// Loop until the current cell exceeds the target cell
	for currentCell <= t {
		// Move to the next cell based on the jump value from the current cell
		currentCell += jumps[currentCell] - 1

		// Check if the current cell is exactly the target cell
		if currentCell == t {
			fmt.Println("YES") // Print "YES" if the target cell is reached
			return            // Exit the program
		}
	}

	// If the loop ends without reaching the target cell, print "NO"
	fmt.Println("NO")
}
