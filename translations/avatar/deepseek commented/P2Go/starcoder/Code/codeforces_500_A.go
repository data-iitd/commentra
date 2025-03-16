
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the number of cells (n) and the target cell (t)
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscanln(reader, &n, &t)

	// Read the list of cells that can be jumped from each cell
	s := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &s[i])
	}

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
			return
		} else {
			// If not, continue to the next iteration
			continue
		}
	}

	// If the loop finishes without finding the target cell, print "NO"
	fmt.Println("NO")
}

