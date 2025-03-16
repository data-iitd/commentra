// Import necessary modules
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function to read input from standard input
func input() string {
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	return strings.TrimSpace(input)
}

// Function to count occurrences of numbers
func count(w map[int]int) int {
	c := 0
	for i := range w {
		if i == 0 {
			c += w[i] * (w[i] - 1)
		} else if -i in w {
			c += w[i] * w[-i]
	}
	return c
}

// Main function
func main() {
	// Read the number of test cases
	n, _ := strconv.Atoi(input())

	// Initialize a map 'w' to store the occurrences of numbers
	w := make(map[int]int)

	// Read the input and store the occurrences of numbers
	for i := 0; i < n; i++ {
		x, _ := strconv.Atoi(input())
		w[x]++
	}

	// Print the result divided by 2
	fmt.Println(count(w) / 2)
}

