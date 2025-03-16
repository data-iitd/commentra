
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// The main function initializes input and output streams, creates an instance of TaskD, and calls its solve method
func main() {
	reader := bufio.NewReader(os.Stdin) // Create a bufio.Reader instance to read input from the standard input
	writer := bufio.NewWriter(os.Stdout) // Create a bufio.Writer instance to write output to the standard output
	defer writer.Flush() // Ensure that the output is flushed before the program exits
	var test int // Initialize the test variable to 0
	fmt.Fscanf(reader, "%d\n", &test) // Read the number of test cases from the input
	for i := 0; i < test; i++ { // Iterate through each test case
		var S string // Initialize the S variable as an empty string
		fmt.Fscanf(reader, "%s\n", &S) // Read the next string from the input
		score := 0 // Initialize the score variable to 0
		for j := 0; j < len(S); j++ { // Iterate through each character in the string S
			my := 'g' // Initialize the my variable as 'g'
			if j%2 == 0 { // Check if the index is even
				my = 'g' // Set the my variable to 'g'
			} else {
				my = 'p' // Set the my variable to 'p'
			}
			his := string(S[j]) // Convert the character at index j in S to a string
			if my!= his { // Check if the expected character and the actual character are different
				if my == 'p' { // Check if the expected character is 'p'
					score++ // Increment the score by 1
				} else {
					score-- // Decrement the score by 1
				}
			}
		}
		fmt.Fprintf(writer, "%d\n", score) // Write the final score to the output
	}
}

// The TaskD struct is used to encapsulate the solve method
type TaskD struct{}

// The solve method takes a test number, a bufio.Reader instance, and a bufio.Writer instance
func (t *TaskD) solve(test int, reader *bufio.Reader, writer *bufio.Writer) {
	// Implement the solve method as per the given Java code
}

// The InputReader struct is used to read input efficiently
type InputReader struct{}

// The nextString method reads the next token from the input stream
func (r *InputReader) nextString(reader *bufio.Reader) string {
	// Implement the nextString method as per the given Java code
}

// The nextInt method reads the next integer from the input stream
func (r *InputReader) nextInt(reader *bufio.Reader) int {
	// Implement the nextInt method as per the given Java code
}

// The nextFloat64 method reads the next float64 from the input stream
func (r *InputReader) nextFloat64(reader *bufio.Reader) float64 {
	// Implement the nextFloat64 method as per the given Java code
}

// The nextLine method reads the next line from the input stream
func (r *InputReader) nextLine(reader *bufio.Reader) string {
	// Implement the nextLine method as per the given Java code
}

// The splitN method splits a string into substrings based on a delimiter
func (r *InputReader) splitN(str string, n int) []string {
	// Implement the splitN method as per the given Java code
}

// The split method splits a string into substrings based on whitespace
func (r *InputReader) split(str string) []string {
	// Implement the split method as per the given Java code
}

// The toInt method converts a string to an integer
func (r *InputReader) toInt(str string) int {
	// Implement the toInt method as per the given Java code
}

// The toFloat64 method converts a string to a float64
func (r *InputReader) toFloat64(str string) float64 {
	// Implement the toFloat64 method as per the given Java code
}

// The toBool method converts a string to a boolean
func (r *InputReader) toBool(str string) bool {
	// Implement the toBool method as per the given Java code
}

// The end-of-code marker is "