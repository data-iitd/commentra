package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Declare a byte slice 'buf' of size 512
	buf := make([]byte, 512)

	// Create a new reader from standard input
	reader := bufio.NewReader(os.Stdin)

	// Read a line from standard input and store it in 'buf'
	reader.Read(buf)

	// Calculate the length of the string read
	len := 0
	for i := 0; i < len(buf); i++ {
		if buf[i] == 0 {
			break
		}
		len++
	}

	// Print the first character of the string, its length (minus 3), and the last character of the string
	fmt.Printf("%c%d%c\n", buf[0], len-3, buf[len-1])
}

