
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Global variables
var (
	reader *bufio.Reader
	writer *bufio.Writer
)

// Function to read input
func readInput() string {
	input, _ := reader.ReadString('\n')
	return strings.TrimSpace(input)
}

// Function to write output
func writeOutput(output string) {
	fmt.Fprintln(writer, output)
}

// Function to close all the open files
func closeFiles() {
	reader.Close()
	writer.Flush()
	writer.Close()
}

// Function to solve the problem
func solve(testNumber int, input *bufio.Reader, output *bufio.Writer) {
	var x string
	var s []rune
	var c int

	x = readInput()
	s = []rune(x)
	c = 0

	for i := 0; i < len(s); i++ {
		s = append(s, s[i])
		for len(s) > 1 {
			p := s[len(s)-1]
			s = s[:len(s)-1]
			q := s[len(s)-1]
			s = s[:len(s)-1]
			if (p == '1' && q == '0') || (p == '0' && q == '1') {
				c++
				continue
			}
			s = append(s, q)
			s = append(s, p)
			break
		}
	}

	writeOutput(strconv.Itoa(c * 2))
}

// Main function
func main() {
	// Reading the number of test cases
	testCases, _ := strconv.Atoi(readInput())

	// Iterating through all the test cases
	for i := 0; i < testCases; i++ {
		solve(i+1, reader, writer)
	}

	// Closing all the files
	closeFiles()
}

// Driver function
func init() {
	// Creating a new reader and writer
	reader = bufio.NewReader(os.Stdin)
	writer = bufio.NewWriter(os.Stdout)
}

