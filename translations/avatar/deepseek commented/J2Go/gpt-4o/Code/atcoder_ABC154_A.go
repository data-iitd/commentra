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

	// Read the first line of input
	str, _ := reader.ReadString('\n')
	strArray := strings.Fields(str)

	// Read the second line of input and split it into tokens
	line, _ := reader.ReadString('\n')
	tokens := strings.Fields(line)

	// Parse the first integer from the tokenized input
	a, _ := strconv.Atoi(tokens[0])

	// Parse the second integer from the tokenized input
	b, _ := strconv.Atoi(tokens[1])

	// Read another string from the input
	u, _ := reader.ReadString('\n')
	u = strings.TrimSpace(u)

	// Check if the read string is equal to the first element of the array and print accordingly
	if u == strArray[0] {
		fmt.Printf("%d %d\n", a-1, b)
	} else {
		fmt.Printf("%d %d\n", a, b-1)
	}
}

// <END-OF-CODE>
