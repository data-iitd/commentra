package main

import (
	"fmt"
	"strings"
)

func main() {
	// Declare a character array 'buf' of size 512
	buf := make([]byte, 512)

	// Declare an integer variable 'len' to store the length of the string read
	var len int

	// Read a line from standard input using fgets() and store it in 'buf'
	fmt.Scanln(&buf)

	// Calculate the length of the string read and store it in 'len'
	len = len(buf)

	// Print the first character of the string, its length (minus 3), and the last character of the string
	fmt.Printf("%c%d%c\n", buf[0], len-3, buf[len-2])
}

