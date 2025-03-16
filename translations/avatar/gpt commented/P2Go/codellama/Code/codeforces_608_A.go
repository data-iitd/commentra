
package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the number of intervals (n) and the starting point (s)
	n, s := readInts()

	// Initialize a variable to keep track of the maximum additional distance (c)
	c := 0

	// Iterate over each interval
	for i := 0; i < n; i++ {
		// Read the start (f) and end (t) of the interval
		f, t := readInts()

		// Calculate the additional distance that can be covered
		x := t - (s - f)

		// Update the maximum additional distance if the current one is greater
		if x > c {
			c = x
		}
	}

	// Output the total distance covered, which is the starting point plus the maximum additional distance
	fmt.Println(s + c)
}

func readInts() (int, int) {
	// Read the input
	input := readLine()

	// Split the input into two integers
	ints := strings.Split(input, " ")

	// Convert the integers to integers
	n, _ := strconv.Atoi(ints[0])
	s, _ := strconv.Atoi(ints[1])

	return n, s
}

func readLine() string {
	// Read the input
	input, _ := os.Readln()

	return input
}

