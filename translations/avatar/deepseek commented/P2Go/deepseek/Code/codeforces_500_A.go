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

	// Read the number of cells (n) and the target cell (t)
	input, _ := reader.ReadString('\n')
	parts := strings.Split(strings.TrimSpace(input), " ")
	n, _ := strconv.Atoi(parts[0])
	t, _ := strconv.Atoi(parts[1])

	// Read the list of cells that can be jumped from each cell
	input, _ = reader.ReadString('\n')
	parts = strings.Split(strings.TrimSpace(input), " ")
	s := make([]int, n)
	for i, part := range parts {
		s[i], _ = strconv.Atoi(part)
	}

	// Initialize the current cell to 0
	current_cell := 0

	// Loop until the current cell exceeds the target cell
	for current_cell <= t {
		// Update the current cell by adding the value of the cell it's currently on
		current_cell += s[current_cell] - 1

		// Check if the current cell is the target cell
		if current_cell == t-1 {
			// If yes, print "YES" and exit the program
			fmt.Println("YES")
			return
		}
	}

	// If the loop finishes without finding the target cell, print "NO"
	fmt.Println("NO")
}

