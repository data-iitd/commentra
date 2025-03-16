package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the number of cells (n) and the target cell (t) from input
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscanln(reader, &n, &t)

	// Read the list of jumps for each cell
	s := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &s[i])
	}

	// Initialize the current cell position
	currentCell := 0

	// Loop until the current cell exceeds the target cell
	for currentCell <= t {
		// Move to the next cell based on the jump value from the current cell
		currentCell += s[currentCell-1]

		// Check if the current cell is exactly the target cell
		if currentCell == t {
			fmt.Println("YES") // Print "YES" if the target cell is reached
			return
		}
	}

	// If the loop ends without reaching the target cell, print "NO"
	fmt.Println("NO")
}

