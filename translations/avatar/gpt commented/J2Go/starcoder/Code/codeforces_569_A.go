package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a new Scanner to read input from stdin
	reader := bufio.NewReader(os.Stdin)

	// Read the first line of input from stdin
	input, _ := reader.ReadString('\n')

	// Split the input into a slice of strings using a " " (space) as the delimiter
	inputSlice := strings.Split(input, " ")

	// Convert the strings in the slice to their integer equivalents and store them in variables
	T, _ := strconv.Atoi(inputSlice[0])
	S, _ := strconv.Atoi(inputSlice[1])
	q, _ := strconv.Atoi(inputSlice[2])

	// Initialize a variable to store the previous value of S
	previous := S

	// Initialize a variable to store the answer
	answer := 0

	// Loop until the previous value is less than T
	for previous < T {
		// Increment the answer
		answer++

		// Multiply the previous value by q
		previous *= q
	}

	// Output the final answer
	fmt.Println(answer)
}

