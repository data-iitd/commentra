package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	// Creating a new Scanner to read input from the console
	scanner := bufio.NewScanner(os.Stdin)
	
	// Reading a line of input from the user
	scanner.Scan()
	input := scanner.Text()
	
	// Replacing commas in the input string with spaces
	modifiedInput := strings.ReplaceAll(input, ",", " ")
	
	// Printing the modified string to the console
	fmt.Println(modifiedInput)
}
