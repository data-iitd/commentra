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

// ReadLongLines reads a specified number of long lines from standard input.
func ReadLongLines(times int) ([]string, error) {
	result := make([]string, times) // Create a slice to hold the lines read
	reader := bufio.NewReader(os.Stdin) // Create a buffered reader for standard input
	buffer := bytes.NewBuffer(make([]byte, 0)) // Buffer to accumulate line data
	readBytes := int64(2) // Initialize readBytes to track the number of bytes read

	// Loop to read the specified number of lines
	for i := 0; i < times; i++ {
		for {
			readBuf, isPrefix, err := reader.ReadLine() // Read a line from input
			readBytes += int64(len(readBuf) + 1) // Update the byte count
			if err != nil {
				if err == io.EOF { // Check for end of file
					fmt.Println("EOF")
					break
				} else {
					return result, err // Return error if reading fails
				}
			}
			_, err = buffer.Write(readBuf) // Write the read buffer to the accumulator
			if err != nil {
				return result, err // Return error if writing fails
			}
			// Check if the line is complete (not a prefix)
			if !isPrefix {
				result[i] = buffer.String() // Store the complete line in the result
				buffer.Reset() // Reset the buffer for the next line
				break // Break out of the inner loop to read the next line
			}
		}
	}
	// Seek back to the previous position to avoid reading ahead
	os.Stdin.Seek(-int64(reader.Buffered()), os.SEEK_CUR)
	return result, nil // Return the lines read
}

// Console struct for handling output
type Console struct {
	writer *bufio.Writer // Buffered writer for output
}

// NewConsole initializes a new Console instance
func NewConsole() Console {
	return Console{bufio.NewWriter(os.Stdout)} // Create a new writer for standard output
}

// Printf formats and writes output to the console
func (this *Console) Printf(format string, a ...interface{}) {
	fmt.Fprintf(this.writer, format, a...) // Format and write to the buffered writer
}

// Println writes a string followed by a newline to the console
func (this *Console) Println(s string) {
	fmt.Fprintln(this.writer, s) // Write the string to the buffered writer
}

// Close flushes the buffered writer
func (this *Console) Close() {
	this.Flush() // Ensure all buffered data is written out
}

// Flush flushes the buffered writer
func (this Console) Flush() {
	this.writer.Flush() // Flush the writer to output
}

// PrintList prints a list of integers to the console
func PrintList(list []int) {
	con := NewConsole() // Create a new console instance
	defer con.Flush() // Ensure flushing on function exit

	// Loop through the list and print each integer
	for i := range list {
		if i == 0 {
			con.Printf("%d", list[i]) // Print the first element without a leading space
		} else {
			con.Printf(" %d", list[i]) // Print subsequent elements with a leading space
		}
	}
	con.Println("") // Print a newline after the list
}

// main function where the program execution begins
func main() {
	con := NewConsole() // Create a new console instance
	defer con.Flush() // Ensure flushing on function exit

	m := make(map[int]struct{}) // Create a map to track unique integers
	lines, _ := ReadLongLines(4) // Read 4 lines from input
	a := strings.Split(lines[1], " ") // Split the second line into individual strings

	// Convert strings to integers and store them in the map
	for i := range a {
		n, _ := strconv.Atoi(a[i]) // Convert string to integer
		m[n] = struct{}{} // Add the integer to the map
	}

	result := make([]int, 0, 200000) // Slice to hold the result integers
	b := strings.Split(lines[3], " ") // Split the fourth line into individual strings

	// Process the integers from the fourth line
	for i := range b {
		n, _ := strconv.Atoi(b[i]) // Convert string to integer
		if _, ok := m[n]; ok { // Check if the integer exists in the map
			delete(m, n) // Remove it from the map if it exists
		} else {
			m[n] = struct{}{} // Add it to the map if it does not exist
		}
	}

	// Collect remaining integers from the map into the result slice
	for k, _ := range m {
		result = append(result, k) // Append the key to the result slice
	}

	// Sort the result slice in ascending order
	sort.Slice(result, func(lhs, rhs int) bool {
		return result[lhs] < result[rhs] // Comparison function for sorting
	})

	// Print the sorted result
	for j := range result {
		con.Printf("%d\n", result[j]) // Print each integer in the result
	}
}
