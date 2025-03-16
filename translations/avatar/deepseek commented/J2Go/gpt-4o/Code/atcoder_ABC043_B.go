package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	// Step 1: Create a scanner for reading input
	scanner := bufio.NewScanner(os.Stdin)

	// Step 2: Read the input string
	scanner.Scan()
	s := scanner.Text()

	// Step 3: Create a string builder to build the result
	var d strings.Builder

	// Step 4: Iterate over each character in the input string
	for _, c := range s {
		switch c {
		case '0':
			// Append '0' to the result
			d.WriteRune('0')
		case '1':
			// Append '1' to the result
			d.WriteRune('1')
		case 'B':
			// Remove the last character if the result is not empty
			if d.Len() > 0 {
				// Remove the last character
				result := d.String()
				d.Reset()
				d.WriteString(result[:len(result)-1])
			}
		}
	}

	// Step 5: Print the result
	fmt.Println(d.String())
}

// <END-OF-CODE>
