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
	
	// Read an integer input which represents the number of elements
	n, _ := strconv.Atoi(readLine(reader))
	
	// Read a line of input, split it by spaces, and convert it to a list of integers
	a := readInts(reader)
	
	// Initialize the current level and counters
	currentLevel := 0
	counter := 0
	counterTurns := -1 // Start with -1 to account for the first turn increment
	
	// Loop until all elements have been processed
	for counter < len(a) {
		counterTurns += 1 // Increment the turn counter
		
		// Iterate through the list to find elements that can be processed
		for i := 0; i < len(a); i++ {
			// Check if the current element is not marked (-1) and is less than or equal to the current counter
			if a[i] != -1 && a[i] <= counter {
				counter += 1 // Increment the counter as we can process this element
				a[i] = -1 // Mark the element as processed by setting it to -1
			}
		}
		
		// Reverse the list to prepare for the next round of processing
		for i, j := 0, len(a)-1; i < j; i, j = i+1, j-1 {
			a[i], a[j] = a[j], a[i]
		}
	}
	
	// Print the total number of turns taken to process all elements
	fmt.Println(counterTurns)
}

// Helper function to read a line of input
func readLine(reader *bufio.Reader) string {
	line, _ := reader.ReadString('\n')
	return strings.TrimSpace(line)
}

// Helper function to read a list of integers from a line of input
func readInts(reader *bufio.Reader) []int {
	line := readLine(reader)
	parts := strings.Split(line, " ")
	ints := make([]int, len(parts))
	for i, part := range parts {
		num, _ := strconv.Atoi(part)
		ints[i] = num
	}
	return ints
}
