package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	// Set up input and output streams
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	// Read four integers from input
	line, _ := reader.ReadString('\n')
	tokens := strings.Fields(line)

	a, _ := strconv.Atoi(tokens[0])
	b, _ := strconv.Atoi(tokens[1])
	c, _ := strconv.Atoi(tokens[2])
	d, _ := strconv.Atoi(tokens[3])

	// Check conditions to determine the output
	if c > b {
		// If c is greater than b, output 0
		fmt.Fprintln(writer, 0)
	} else if a > d {
		// If a is greater than d, output 0
		fmt.Fprintln(writer, 0)
	} else if a < c {
		// If a is less than c, calculate and output the difference
		fmt.Fprintln(writer, min(b, d)-c)
	} else {
		// Create a slice to hold the four integers
		numbers := []int{a, b, c, d}

		// Sort the slice to find the second largest and third largest values
		sort.Ints(numbers)

		// Output the difference between the second largest and third largest values
		fmt.Fprintln(writer, numbers[2]-numbers[1])
	}
}

// min function to return the minimum of two integers
func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

// <END-OF-CODE>
