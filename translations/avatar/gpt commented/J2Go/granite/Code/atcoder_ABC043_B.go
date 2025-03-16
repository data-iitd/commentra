
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Set up input and output streams
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)

	// Read the input string
	s, _ := reader.ReadString('\n')
	s = s[:len(s)-1]

	// StringBuilder to construct the output string
	d := ""

	// Process each character in the input string
	for _, c := range s {
		switch c {
		case '0':
			// Append '0' to the output
			d += "0"
		case '1':
			// Append '1' to the output
			d += "1"
		case 'B':
			// Handle the 'B' character by removing the last character if possible
			if len(d) > 0 {
				d = d[:len(d)-1]
			}
		}
	}

	// Output the final result
	fmt.Fprintln(writer, d)
	writer.Flush()
}

// END-OF-CODE