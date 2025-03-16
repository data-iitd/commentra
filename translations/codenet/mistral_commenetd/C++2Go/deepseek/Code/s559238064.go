package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var a int
	var z string

	// Read input string from standard input
	fmt.Fscan(reader, &z)
	// Assign size of the string to variable 'a'
	a = len(z)

	// Check if there are any consecutive identical characters in the string
	for i := 0; i < a - 1; i++ {
		// Check if current character is same as next character
		if z[i] == z[i + 1] {
			// If yes, print "Bad" and exit the program
			fmt.Fprintln(writer, "Bad")
			return
		}
	}
	// If no consecutive identical characters are found, print "Good"
	fmt.Fprintln(writer, "Good")
}

