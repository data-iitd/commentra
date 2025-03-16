
package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the number of cells (n) and the target cell (t) from input
	n, t := readInput()

	// Read the list of jumps for each cell
	s := readJumps(n)

	// Initialize the current cell position
	currentCell := 0

	// Loop until the current cell exceeds the target cell
	for currentCell <= t {
		// Move to the next cell based on the jump value from the current cell
		currentCell += s[currentCell-1]

		// Check if the current cell is exactly the target cell
		if currentCell == t {
			fmt.Println("YES") // Print "YES" if the target cell is reached
			os.Exit(0)          // Exit the program
		}
	}

	// If the loop ends without reaching the target cell, print "NO"
	fmt.Println("NO")
}

func readInput() (int, int) {
	// Read the input from the command line
	input := strings.Split(readLine(), " ")

	// Convert the input to integers
	n, _ := strconv.Atoi(input[0])
	t, _ := strconv.Atoi(input[1])

	return n, t
}

func readJumps(n int) []int {
	// Read the list of jumps for each cell
	s := make([]int, n)
	for i := 0; i < n; i++ {
		s[i], _ = strconv.Atoi(readLine())
	}

	return s
}

func readLine() string {
	var line string
	fmt.Scanln(&line)
	return line
}

