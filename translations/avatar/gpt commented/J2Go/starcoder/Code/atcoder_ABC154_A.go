package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a new buffered reader.
	reader := bufio.NewReader(os.Stdin)

	// Read a line of input from stdin and save it to a string.
	input, _ := reader.ReadString('\n')

	// Split the input string into a slice of strings.
	inputSlice := strings.Split(input, " ")

	// Convert the first element of the slice to an integer and save it to a variable.
	a, _ := strconv.Atoi(inputSlice[0])

	// Convert the second element of the slice to an integer and save it to a variable.
	b, _ := strconv.Atoi(inputSlice[1])

	// Read a line of input from stdin and save it to a string.
	input, _ = reader.ReadString('\n')

	// Print the result of the comparison.
	fmt.Println(input == inputSlice[0] && a-1 == b || a == b-1)
}

