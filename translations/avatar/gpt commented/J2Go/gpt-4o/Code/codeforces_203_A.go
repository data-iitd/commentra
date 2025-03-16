package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	run()
}

func run() {
	reader := bufio.NewReader(os.Stdin) // Initialize BufferedReader
	writer := bufio.NewWriter(os.Stdout) // Initialize BufferedWriter
	defer writer.Flush()                  // Ensure the buffer is flushed at the end

	x, t, a, b, da, db := readInts(reader) // Read input values
	ok := false                              // Flag to indicate if the target can be reached

	// Iterate through possible steps for the first entity
	for i := 0; i < t; i++ {
		first := a - (da * i) // Calculate position of first entity

		// Iterate through possible steps for the second entity
		for j := 0; j < t; j++ {
			second := b - (db * j) // Calculate position of second entity

			// Check if any of the conditions to reach target x are met
			if second+first == x || second == x || first == x || x == 0 {
				ok = true // Set flag to true if target is reachable
				break     // Exit inner loop if target is found
			}
		}
	}

	// Output result based on whether the target can be reached
	if ok {
		writer.WriteString("YES\n") // Target can be reached
	} else {
		writer.WriteString("NO\n") // Target cannot be reached
	}
}

// Function to read multiple integers from input
func readInts(reader *bufio.Reader) (int, int, int, int, int, int) {
	line, _ := reader.ReadString('\n') // Read a line from input
	parts := strings.Fields(line)       // Split the line into parts

	// Parse the parts into integers
	x, _ := strconv.Atoi(parts[0])
	t, _ := strconv.Atoi(parts[1])
	a, _ := strconv.Atoi(parts[2])
	b, _ := strconv.Atoi(parts[3])
	da, _ := strconv.Atoi(parts[4])
	db, _ := strconv.Atoi(parts[5])

	return x, t, a, b, da, db
}
