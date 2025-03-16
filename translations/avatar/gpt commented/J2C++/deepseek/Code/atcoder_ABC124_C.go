package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Set up input and output streams
	inputStream := os.Stdin
	outputStream := os.Stdout
	
	// Create a scanner to read input from the input stream
	scanner := bufio.NewScanner(inputStream)
	
	// Create a writer to write output to the output stream
	writer := bufio.NewWriter(outputStream)
	
	// Instantiate the solver struct for the problem
	solver := CColoringColorfully{}
	
	// Solve the problem for the first test case
	solver.solve(scanner, writer)
	
	// Flush the writer to ensure all output is written
	writer.Flush()
}

type CColoringColorfully struct {}

func (solver CColoringColorfully) solve(scanner *bufio.Scanner, writer *bufio.Writer) {
	// Read the input string
	scanner.Scan()
	x := scanner.Text()
	
	// Create two strings to manipulate the string
	a := []rune(x)
	b := []rune(x)
	
	// Initialize counters for the number of changes made
	a1 := 0
	a2 := 0
	
	// First pass: modify 'a' from left to right
	for i := 1; i < len(x); i++ {
		// Check if the current character is the same as the previous one
		if a[i] == a[i - 1] {
			// Change the character to the opposite value
			if a[i] == '1' {
				a[i] = '0'
			} else {
				a[i] = '1'
			}
			
			// Increment the change counter
			a1++
		}
	}
	
	// Second pass: modify 'b' from right to left
	for i := len(x) - 1; i > 0; i-- {
		// Check if the current character is the same as the previous one
		if b[i] == b[i - 1] {
			// Change the previous character to the opposite value
			if b[i - 1] == '1' {
				b[i - 1] = '0'
			} else {
				b[i - 1] = '1'
			}
			
			// Increment the change counter
			a2++
		}
	}
	
	// Output the minimum number of changes made in either pass
	if a1 < a2 {
		writer.WriteString(strconv.Itoa(a1) + "\n")
	} else {
		writer.WriteString(strconv.Itoa(a2) + "\n")
	}
}

