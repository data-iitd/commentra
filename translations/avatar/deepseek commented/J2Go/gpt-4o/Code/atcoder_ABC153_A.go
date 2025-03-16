package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Reading input from standard input
	var input string
	fmt.Scanln(&input)

	// Splitting the input by spaces
	str := strings.Split(input, " ")
	h, _ := strconv.Atoi(str[0]) // Parsing the first element to an integer representing the height
	a, _ := strconv.Atoi(str[1]) // Parsing the second element to an integer representing the amount to subtract
	num := 0                      // Initializing a counter to keep track of the number of subtractions

	// Implementing a loop to subtract 'a' from 'h' until 'h' is less than or equal to 0
	for h > 0 {
		h -= a // Subtracting 'a' from 'h'
		num++  // Incrementing the counter
	}

	fmt.Println(num) // Printing the result, which is the number of subtractions
}

// <END-OF-CODE>
