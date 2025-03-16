package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Use bufio for faster input reading
	reader := bufio.NewReader(os.Stdin)

	// Read the number of elements
	n, _ := strconv.Atoi(readLine(reader))

	// Read the list of integers from input
	w := readInts(reader)

	// Initialize a variable 'c' to track the output state
	c := 2

	// Iterate through each element in the list 'w'
	for _, i := range w {
		// If the current element is 1, print the current value of 'c'
		if i == 1 {
			fmt.Println(c)
		} else if i%2 == 0 {
			// If the current element is even, toggle 'c' between 2 and 3
			c = 3 - c // This will switch c between 2 and 3
			fmt.Println(c)
		} else {
			// If the current element is odd (and not 1), print the current value of 'c'
			fmt.Println(c)
		}
	}
}

// Helper function to read a line of input
func readLine(reader *bufio.Reader) string {
	line, _ := reader.ReadString('\n')
	return line[:len(line)-1] // Remove the newline character
}

// Helper function to read a list of integers from input
func readInts(reader *bufio.Reader) []int {
	line, _ := reader.ReadString('\n')
	ints := []int{}
	for _, s := range strings.Split(line[:len(line)-1], " ") {
		num, _ := strconv.Atoi(s)
		ints = append(ints, num)
	}
	return ints
}
