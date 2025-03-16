package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the dimensions of the grid (n) and the number of operations (m)
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	line = strings.TrimSpace(line)
	n, _ := strconv.Atoi(line)
	line, _ = reader.ReadString('\n')
	line = strings.TrimSpace(line)
	m, _ := strconv.Atoi(line)

	// Initialize a 2D list to keep track of counts for each cell in the grid
	count := make([][]int, n)
	for i := 0; i < n; i++ {
		count[i] = make([]int, n)
	}

	ans := -1  // Initialize the answer variable to -1 (indicating no solution found)

	// Process each operation
	for k := 0; k < m; k++ {
		// Read the coordinates for the current operation and adjust for 0-based indexing
		line, _ := reader.ReadString('\n')
		line = strings.TrimSpace(line)
		x, _ := strconv.Atoi(line)
		line, _ = reader.ReadString('\n')
		line = strings.TrimSpace(line)
		y, _ := strconv.Atoi(line)
		x -= 1
		y -= 1

		found := false  // Flag to indicate if a cell has reached the count of 9

		// Iterate over the 3x3 grid centered at (x, y)
		for i := x - 2; i <= x + 1; i++ {
			for j := y - 2; j <= y + 1; j++ {
				// Check if the indices are within the bounds of the grid
				if i >= 0 && i < n && j >= 0 && j < n {
					count[i][j] += 1  // Increment the count for the current cell

					// Check if the count for this cell has reached 9
					if count[i][j] == 9 {
						found = true  // Mark that we found a cell with count 9
			}
		}

		// If a cell with count 9 was found, update the answer and break the loop
		if found {
			ans = k + 1  // Store the 1-based index of the operation
			break
		}
	}

	// Print the result: the operation number where a cell reached count 9, or -1 if none did
	fmt.Println(ans)
}

// 