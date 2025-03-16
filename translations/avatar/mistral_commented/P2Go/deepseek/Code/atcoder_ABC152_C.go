package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a new reader for reading input
	reader := bufio.NewReader(os.Stdin)

	// Read the number of elements in the array
	N, _ := strconv.Atoi(readLine(reader))

	// Initialize an empty slice 'n' of size N
	n := make([]int, N)

	// Read the elements of the array from user input and store them in 'n'
	input, _ := readLine(reader)
	elements := strings.Split(input, " ")
	for i := 0; i < N; i++ {
		n[i], _ = strconv.Atoi(elements[i])
	}

	// Initialize variables 'a' and 'pos'
	a := 1
	pos := 0

	// Iterate through the slice 'n' starting from the second element
	for i := 1; i < N; i++ {
		// Check if the current element is greater than the previous one
		if n[pos] > n[i] {
			// Increment the variable 'a' if the condition is true
			a += 1
			// Update the position of the previous greater element
			pos = i
		}
	}

	// Print the value of 'a' as the output
	fmt.Println(a)
}

// Helper function to read a line from the reader
func readLine(reader *bufio.Reader) string {
	input, _ := reader.ReadString('\n')
	return strings.TrimSpace(input)
}
