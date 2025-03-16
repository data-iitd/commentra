package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read input values: the number of initial candles (candeleIntere) and the number of candles needed to create a new one (b)
	candeleIntere, b := readInput()

	// Initialize total candles burned (s) and remaining loose candles (restoSciolte)
	s := 0
	restoSciolte := 0

	// Loop until there are no more candles to burn or we have enough loose candles to create a new one
	for candeleIntere > 0 || restoSciolte >= b {
		// Calculate how many new candles can be created from the remaining loose candles
		candeleIntere += restoSciolte / b

		// Update the number of loose candles after creating new candles
		restoSciolte %= b

		// Add the current number of candles to the total burned count
		s += candeleIntere

		// Update the number of loose candles with the remainder from the current candles
		restoSciolte += candeleIntere % b

		// Reduce the number of candles by the number of new candles created
		candeleIntere /= b
	}

	// Print the total number of candles burned
	fmt.Println(s)
}

func readInput() (candeleIntere, b int) {
	// Read input from stdin
	s := bufio.NewScanner(os.Stdin)
	s.Scan()
	input := s.Text()

	// Split the input into a slice of strings
	inputSlice := strings.Split(input, " ")

	// Convert the strings to integers
	candeleIntere, _ = strconv.Atoi(inputSlice[0])
	b, _ = strconv.Atoi(inputSlice[1])

	return candeleIntere, b
}

