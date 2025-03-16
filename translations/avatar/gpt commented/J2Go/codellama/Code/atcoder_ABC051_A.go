package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	// Creating a BufferedReader to read input from the console
	br := bufio.NewReader(os.Stdin)

	// Using a StringBuilder to efficiently build the output string
	var sb strings.Builder

	// Reading a line of input from the user
	a, _ := br.ReadString('\n')

	// Replacing commas in the input string with spaces and appending to StringBuilder
	sb.WriteString(strings.Replace(a, ",", " ", -1))

	// Printing the modified string to the console
	fmt.Println(sb.String())
}

