package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	// Read the number of rounds (n) and the number of George's complexities (m)
	n, m := readInts()

	// Read the complexities for each round into a list
	roundComplexity := readInts()

	// Read George's complexities into another list
	georgeComplexity := readInts()

	// Initialize indices for both lists
	i, j := 0, 0

	// Iterate through both lists to compare complexities
	for i < n && j < m {
		// If the current round's complexity is less than or equal to George's complexity,
		// move to the next round
		if roundComplexity[i] <= georgeComplexity[j] {
			i++
		}

		// Always move to the next complexity of George
		j++
	}

	// Output the number of rounds that George cannot handle
	fmt.Println(n - i)
}

func readInts() (int, int) {
	// Read the input
	input := readLine()

	// Split the input into two parts
	parts := strings.Split(input, " ")

	// Convert the parts to integers
	n, _ := strconv.Atoi(parts[0])
	m, _ := strconv.Atoi(parts[1])

	// Return the integers
	return n, m
}

func readLine() string {
	var line string
	fmt.Scanln(&line)
	return line
}

// 