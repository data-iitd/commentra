package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read input from stdin
	h1, m1, h2, m2, k := readInput()

	// Calculate the total minutes from the start time to the end time
	ans := h2*60 + m2 - (h1*60 + m1)

	// Output the result after subtracting the duration k from the total minutes
	fmt.Println(ans - k)
}

func readInput() (int, int, int, int, int) {
	// Read input from stdin
	input, _ := os.Stdin.ReadString('\n')

	// Split the input into individual values
	input = strings.Split(input, " ")

	// Convert the individual values to integers
	h1, _ := strconv.Atoi(input[0])
	m1, _ := strconv.Atoi(input[1])
	h2, _ := strconv.Atoi(input[2])
	m2, _ := strconv.Atoi(input[3])
	k, _ := strconv.Atoi(input[4])

	return h1, m1, h2, m2, k
}

