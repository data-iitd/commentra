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
	
	// Read the integer input representing the length of the list `a`
	n, _ := strconv.Atoi(readLine(reader))
	
	// Read the space-separated string of integers and convert them to a list `a` of integers
	input, _ := reader.ReadString('\n')
	a := parseInts(input)
	
	// Initialize an empty list `b` of length `n`
	b := make([]int, n)
	
	// Assign the index of each element in `a` to the corresponding position in `b`, adjusting for zero-based indexing
	for i := 0; i < n; i++ {
		b[a[i]-1] = i
	}
	
	res := 0 // Initialize the result variable `res` to 0
	
	// Calculate the sum of absolute differences between the positions of consecutive elements in `b`
	for i := 1; i < n; i++ {
		res += abs(b[i] - b[i-1])
	}
	
	// Print the result
	fmt.Println(res)
}

// Helper function to read a line from the reader
func readLine(reader *bufio.Reader) string {
	input, _ := reader.ReadString('\n')
	return strings.TrimRight(input, "\r\n")
}

// Helper function to convert a space-separated string to a list of integers
func parseInts(input string) []int {
	parts := strings.Fields(input)
	ints := make([]int, len(parts))
	for i, part := range parts {
		ints[i], _ = strconv.Atoi(part)
	}
	return ints
}

// Helper function to calculate the absolute value of an integer
func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
