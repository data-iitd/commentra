package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Use bufio for faster input
	reader := bufio.NewReader(os.Stdin)

	// Read the number of elements
	n, _ := strconv.Atoi(readLine(reader))

	// Read the list of integers
	w := readInts(reader)

	// Calculate the sum of the list
	x := 0
	for _, v := range w {
		x += v
	}

	// Initialize an empty list to store indices
	d := []int{}

	// Iterate through each element in the list
	for i := 0; i < n; i++ {
		// Check if removing the current element results in an average equal to the current element
		if (x-w[i])/(n-1) == w[i] {
			// If the condition is met, append the 1-based index to the list
			d = append(d, i+1)
		}
	}

	// Print the number of valid indices found
	fmt.Println(len(d))

	// Print the valid indices as a space-separated string
	fmt.Println(strings.Trim(fmt.Sprint(d), "[]"))
}

// Helper function to read a line of input
func readLine(reader *bufio.Reader) string {
	line, _ := reader.ReadString('\n')
	return strings.TrimRight(line, "\n")
}

// Helper function to read a list of integers from a line
func readInts(reader *bufio.Reader) []int {
	line, _ := reader.ReadString('\n')
	parts := strings.Fields(strings.TrimRight(line, "\n"))
	ints := []int{}
	for _, part := range parts {
		num, _ := strconv.Atoi(part)
		ints = append(ints, num)
	}
	return ints
}
