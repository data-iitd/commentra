package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Get the number of candles 'candeleIntere' and the box size 'b' from user input
	candeleIntere, b := getInput()

	// Initialize the sum's' to 0
	s := 0

	// Initialize the remaining candles'restoSciolte' to 0
	restoSciolte := 0

	// Continue the loop as long as there are still candles or the remaining candles are greater than or equal to the box size
	for candeleIntere > 0 || restoSciolte >= b {

		// Calculate the number of full boxes of candles that can be put in the box
		candeleIntere += restoSciolte / b

		// Update the remaining candles
		restoSciolte %= b

		// Add the number of candles in the current box to the sum
		s += candeleIntere

		// Update the remaining candles by adding the remainder of the current box
		restoSciolte += candeleIntere % b

		// Update the number of candles to be put in the next box
		candeleIntere /= b
	}

	// Print the sum
	fmt.Println(s)
}

func getInput() (int, int) {
	// Get the user input
	s := bufio.NewScanner(os.Stdin)
	s.Scan()
	input := s.Text()

	// Split the input into a slice of strings
	inputSlice := strings.Split(input, " ")

	// Convert the first and second elements of the slice to integers
	candeleIntere, _ := strconv.Atoi(inputSlice[0])
	b, _ := strconv.Atoi(inputSlice[1])

	// Return the two integers
	return candeleIntere, b
}

