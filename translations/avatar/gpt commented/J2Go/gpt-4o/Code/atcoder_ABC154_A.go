package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a BufferedReader to read input from the standard input stream
	reader := bufio.NewReader(os.Stdin)

	// Read a line of input, split it by spaces, and store it in a slice
	str, _ := reader.ReadString('\n')
	strArray := strings.Fields(str)

	// Read the next line of input
	line, _ := reader.ReadString('\n')
	tokens := strings.Fields(line)

	// Parse the first token as an integer and store it in variable 'a'
	a, _ := strconv.Atoi(tokens[0])

	// Parse the second token as an integer and store it in variable 'b'
	b, _ := strconv.Atoi(tokens[1])

	// Read another line of input and store it in variable 'u'
	u, _ := reader.ReadString('\n')
	u = strings.TrimSpace(u)

	// Compare the string 'u' with the first element of the array 'strArray'
	// Print the result based on the comparison
	if u == strArray[0] {
		fmt.Printf("%d %d\n", a-1, b)
	} else {
		fmt.Printf("%d %d\n", a, b-1)
	}
}

// <END-OF-CODE>
