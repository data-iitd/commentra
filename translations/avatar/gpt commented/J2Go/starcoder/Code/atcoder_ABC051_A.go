package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	// Creating a new buffered reader to read input from the console
	reader := bufio.NewReader(os.Stdin)

	// Reading a line of input from the user
	input, _ := reader.ReadString('\n')

	// Replacing commas in the input string with spaces
	output := strings.Replace(input, ",", " ", -1)

	// Printing the modified string to the console
	fmt.Println(output)
}

