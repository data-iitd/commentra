package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	// Read input from stdin
	reader := bufio.NewReader(os.Stdin)
	// Read the first line of input
	input, _ := reader.ReadString('\n')
	// Remove the trailing newline character
	input = strings.TrimSuffix(input, "\n")
	// Print the output to stdout
	fmt.Println(strings.Contains(input, "A") && strings.Contains(input, "B"))
}

