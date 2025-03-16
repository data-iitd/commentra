package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a new scanner to read input from the console
	scanner := bufio.NewScanner(os.Stdin)

	// Read a line of input from the console
	scanner.Scan()

	// Split the input into an array of strings
	input := strings.Split(scanner.Text(), " ")

	// Parse the first and second elements of the array as integers
	a, _ := strconv.Atoi(input[0])
	b, _ := strconv.Atoi(input[1])

	// Calculate the value of c based on the formula: c = a - b * 2
	c := a - b*2

	// If c is negative, set it to 0
	if c < 0 {
		c = 0
	}

	// Output the final value of c
	fmt.Println(c)
}

