package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a new Scanner to read input from stdin.
	reader := bufio.NewReader(os.Stdin)

	// Read the first line of input from stdin.
	input, _ := reader.ReadString('\n')

	// Split the input into two space-delimited integers.
	input = strings.TrimSpace(input)
	input_array := strings.Split(input, " ")
	a, _ := strconv.Atoi(input_array[0])
	b, _ := strconv.Atoi(input_array[1])

	// Initialize variables to hold the remainder and the result.
	amari := 0
	result := 0

	// Calculate the initial result based on the formula (B - 1) / (A - 1).
	result = (b - 1) / (a - 1)

	// Calculate the remainder when (B - 1) is divided by (A - 1).
	amari = (b - 1) % (a - 1)

	// If there is a remainder, increment the result by 1.
	if amari!= 0 {
		result += 1
	}

	// Output the final result to stdout.
	fmt.Println(result)
}

