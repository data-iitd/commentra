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

	// Read four integers from input
	a, _ := strconv.Atoi(readLine(reader))
	b, _ := strconv.Atoi(readLine(reader))
	c, _ := strconv.Atoi(readLine(reader))
	d, _ := strconv.Atoi(readLine(reader))

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
		// Create a list to hold the four integers
		l := []int{a, b, c, d}

		// Sort the list to find the second largest and third largest values
		sort.Ints(l)

		// Output the difference between the second largest and third largest values
		fmt.Fprintln(writer, l[2]-l[1])
	}

	// Close the input and output streams
	writer.Flush()
}

// ReadLine reads a line from the input stream.
func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}
	return strings.TrimRight(string(str), "\r\n")
}

// min returns the minimum of two integers.
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

