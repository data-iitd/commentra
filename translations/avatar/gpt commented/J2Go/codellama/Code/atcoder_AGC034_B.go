package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	// Initialize input and output streams
	inputStream := os.Stdin
	outputStream := os.Stdout

	// Create a Scanner object for reading input
	in := bufio.NewScanner(inputStream)

	// Create a PrintWriter object for writing output
	out := bufio.NewWriter(outputStream)

	// Create an instance of the BABC class to solve the problem
	solver := BABC{}

	// Call the solve method with test number, input scanner, and output writer
	solver.solve(1, in, out)

	// Close the output writer
	out.Flush()
}

type BABC struct{}

func (solver *BABC) solve(testNumber int, in *bufio.Scanner, out *bufio.Writer) {
	// Read the input string and replace occurrences of "BC" with "D"
	s := in.Text()
	s = strings.Replace(s, "BC", "D", -1)

	// Initialize counters for 'A' and the result
	cnt := 0
	tmp := 0

	// Iterate through the modified string to count occurrences
	for i := 0; i < len(s); i++ {
		// Increment temporary counter for 'A'
		if s[i] == 'A' {
			tmp++
		}
		// Add the count of 'A's to the result when 'D' is encountered
		else if s[i] == 'D' {
			cnt += tmp
		}
		// Reset the temporary counter for any other character
		else {
			tmp = 0
		}
	}

	// Output the final count of valid pairs
	fmt.Fprintln(out, cnt)
}

// 