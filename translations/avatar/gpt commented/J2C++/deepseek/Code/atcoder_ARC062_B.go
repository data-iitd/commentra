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
	
	// Read the input string S
	scanner.Scan()
	S := scanner.Text()
	
	// Initialize score to zero
	score := 0
	
	// Iterate through each character in the string S
	for i := 0; i < len(S); i++ {
		// Determine the character for 'my' based on the index (even or odd)
		my := 'g'
		if i % 2 == 0 {
			my = 'g'
		} else {
			my = 'p'
		}
		
		// Get the character from the input string at the current index
		his := rune(S[i])
		
		// Compare 'my' and 'his' characters to update the score
		if my != his {
			// Increment score if 'my' is 'p', otherwise decrement
			if my == 'p' {
				score++
			} else {
				score--
			}
		}
	}
	
	// Output the final score
	fmt.Fprintln(writer, score)
	
	// Flush the writer to ensure all output is written
	writer.Flush()
}
