package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Initialize input and output streams
	inputReader := bufio.NewReader(os.Stdin)
	outputWriter := bufio.NewWriter(os.Stdout)
	defer outputWriter.Flush()

	// Read input integers a, b, c, and d
	input, _ := inputReader.ReadString('\n')
	inputs := strings.Fields(input)
	a, _ := strconv.Atoi(inputs[0])
	b, _ := strconv.Atoi(inputs[1])
	c, _ := strconv.Atoi(inputs[2])
	d, _ := strconv.Atoi(inputs[3])

	// Check if c is greater than b
	if c > b {
		// If yes, print 0 and exit
		fmt.Fprintln(outputWriter, 0)
		return
	}

	// Check if a is greater than d
	if a > d {
		// If yes, print 0 and exit
		fmt.Fprintln(outputWriter, 0)
		return
	}

	// Check if a is less than c
	if a < c {
		// If yes, calculate the difference between the smaller and larger of b and d
		difference := min(b, d) - c
		// Print the difference
		fmt.Fprintln(outputWriter, difference)
		return
	}

	// If none of the above conditions are true, then a, b, c, and d are in sorted order
	// Create a List of integers a, b, c, and d
	var l []int
	l = append(l, a, b, c, d)

	// Sort the List in ascending order
	sort.Ints(l)

	// Calculate the difference between the second and third elements of the List
	difference := l[2] - l[1]

	// Print the difference
	fmt.Fprintln(outputWriter, difference)
}

// Helper function to find the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

