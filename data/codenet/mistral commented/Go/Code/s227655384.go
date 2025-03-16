// Package main is the entry point of the program
package main

import (
	"bufio"
	"bytes"
	"fmt"
	"io"
	"os"

	"sort"
	"strconv"
	"strings"
)

// ReadLongLines function reads long lines from standard input
func ReadLongLines(times int) ([]string, error) {
	// Initialize result slice with the given size
	result := make([]string, times)
	// Initialize a new buffered reader
	reader := bufio.NewReader(os.Stdin)
	// Initialize a new bytes.Buffer
	buffer := bytes.NewBuffer(make([]byte, 0))
	// Initialize readBytes variable to keep track of the total number of bytes read
	readBytes := int64(2)

	// For each iteration, read a line from the standard input
	for i := 0; i < times; i++ {
		// Read a line from the standard input
		for {
			// Read a line from the standard input
			readBuf, isPrefix, err := reader.ReadLine()
			// Check if an error occurred during the read operation
			if err != nil {
				// If the error is of type io.EOF, it means that the end of the input has been reached
				if err == io.EOF {
					fmt.Println("EOF")
					// Break the loop if the end of the input has been reached
					break
				} else {
					// Return an error if an error other than io.EOF occurred
					return result, err
				}
			}
			// Write the read line to the buffer
			_, err = buffer.Write(readBuf)
			// Check if an error occurred during the write operation
			if err != nil {
				// Return an error if an error occurred during the write operation
				return result, err
			}
			// Check if the line read is the last line of the input
			if !isPrefix {
				// Store the content of the line in the result slice
				result[i] = buffer.String()
				// Reset the buffer for the next iteration
				buffer.Reset()
				// Break the inner loop if the line read is the last line of the input
				break
			}
		}
		// Seek back the standard input stream to the position before the last read operation
		os.Stdin.Seek(-int64(reader.Buffered()), os.SEEK_CUR)
	}
	// Return the result and nil error
	return result, nil
}

// Console type is used to manage the standard output
type Console struct {
	writer *bufio.Writer
}

// NewConsole function initializes a new Console instance
func NewConsole() Console {
	// Initialize a new Console instance with the standard output as the writer
	return Console{bufio.NewWriter(os.Stdout)}
}

// Printf function prints formatted strings to the Console writer
func (this *Console) Printf(format string, a ...interface{}) {
	// Format and print the given arguments to the Console writer
	fmt.Fprintf(this.writer, format, a...)
}

// Println function prints a newline character followed by the given string to the Console writer
func (this *Console) Println(s string) {
	// Format and print the given string followed by a newline character to the Console writer
	fmt.Fprintln(this.writer, s)
}

// Close function flushes the Console writer and closes it
func (this Console) Close() {
	// Flush and close the Console writer
	this.Flush()
}

// Flush function flushes the Console writer
func (this Console) Flush() {
	// Flush the Console writer
	this.writer.Flush()
}

// PrintList function prints an integer slice to the standard output
func PrintList(list []int) {
	// Initialize a new Console instance
	con := NewConsole()
	// Defer the Flush function to be called when the function returns
	defer con.Flush()
	// Iterate through the given integer slice and print each element to the standard output
	for i := range list {
		// If it's the first element, print it without a separator
		if i == 0 {
			con.Printf("%d", list[i])
		} else {
			// Otherwise, print it with a separator
			con.Printf(" %d", list[i])
		}
	}
	// Print a newline character to the standard output
	con.Println("")
}

// main function is the entry point of the program
func main() {
	// Initialize a new Console instance
	con := NewConsole()
	// Defer the Flush function to be called when the function returns
	defer con.Flush()

	// Initialize an empty map to store unique integers
	m := make(map[int]struct{})
	// Read long lines from the standard input
	lines, _ := ReadLongLines(4)
	// Split the second line into an integer slice
	a := strings.Split(lines[1], " ")
	// Iterate through the integer slice and add each integer to the map
	for i := range a {
		// Parse the integer from the string and add it to the map
		n, _ := strconv.Atoi(a[i])
		m[n] = struct{}{}
	}

	// Read integers from the fourth line and add them to the map if they are not already present
	b := strings.Split(lines[3], " ")
	for i := range b {
		// Parse the integer from the string and add it to the map if it's not already present
		n, _ := strconv.Atoi(b[i])
		if _, ok := m[n]; !ok {
			m[n] = struct{}{}
		}
	}

	// Extract the unique integers from the map and store them in a slice
	result := make([]int, 0, 200000)
	for k, _ := range m {
		// Append the integer to the result slice
		result = append(result, k)
	}

	// Sort the result slice in ascending order
	sort.Slice(result, func(lhs, rhs int) bool {
		return result[lhs] < result[rhs]
	})

	// Iterate through the sorted result slice and print each integer to the standard output
	for j := range result {
		// Print each integer to the standard output
		con.Printf("%d\n", result[j])
	}
}

// 