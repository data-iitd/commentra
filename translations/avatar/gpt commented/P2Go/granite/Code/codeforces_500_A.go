
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Read the number of cells (n) and the target cell (t) from input
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(readerReadLine(reader))
	t, _ := strconv.Atoi(readerReadLine(reader))

	// Read the list of jumps for each cell
	s := readerReadSlice(reader)

	// Initialize the current cell position
	currentCell := 0

	// Loop until the current cell exceeds the target cell
	for currentCell <= t {
		// Move to the next cell based on the jump value from the current cell
		currentCell += s[currentCell-1]

		// Check if the current cell is exactly the target cell
		if currentCell == t {
			fmt.Println("YES") // Print "YES" if the target cell is reached
			return             // Return from the function
		}
	}

	// If the loop ends without reaching the target cell, print "NO"
	fmt.Println("NO")
}

func readerReadLine(reader *bufio.Reader) string {
	line, _, _ := reader.ReadLine()
	return string(line)
}

func readerReadSlice(reader *bufio.Reader) []int {
	line, _, _ := reader.ReadLine()
	slice := make([]int, 0)
	for _, part := range strings.Split(string(line), " ") {
		value, _ := strconv.Atoi(part)
		slice = append(slice, value)
	}
	return slice
}

