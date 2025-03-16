package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Declare variables to hold the values of A, B, K, and the results x, y
	var A, B, K, x, y int64

	// Set up input reading from standard input with UTF-8 encoding
	reader := bufio.NewReader(os.Stdin)

	// Read a line of input, split it into tokens, and parse them as long integers
	line, _ := reader.ReadString('\n')
	tokens := strings.Split(line, " ")
	A, _ = strconv.ParseInt(tokens[0], 10, 64)
	B, _ = strconv.ParseInt(tokens[1], 10, 64)
	K, _ = strconv.ParseInt(tokens[2], 10, 64)

	// Perform calculations based on the input values
	x = A - K
	if x < 0 {
		x = 0
		y = B + x
	} else {
		y = B
	}

	// Display the results of the calculations
	fmt.Println(x, y)
}

