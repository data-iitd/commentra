package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Reading input from the console
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')

	// Splitting the input string into an array of strings
	input = strings.Split(input, " ")

	// Parsing the first two elements of the array as integers
	h, _ := strconv.Atoi(input[0])
	a, _ := strconv.Atoi(input[1])

	// Initializing a variable to keep track of the number of steps
	num := 0

	// Using a for loop to simulate the given condition
	for i := 1; h > 0; i++ {

		// Subtracting 'a' from 'h' in each iteration
		h = h - a

		// Incrementing the 'num' variable after each successful subtraction
		num++
	}

	// Printing the final result 'num' to the console
	fmt.Println(num)
}

