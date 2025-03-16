package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Creating a new scanner object to read input from the console
	scanner := bufio.NewScanner(os.Stdin)

	// Reading an integer input from the user
	scanner.Scan()
	x, _ := strconv.Atoi(scanner.Text())

	// Using a ternary operator to determine the boolean value based on the input
	bool := x == 1

	// Setting the result based on the boolean value; if bool is false, result is 1, otherwise 0
	result := 0
	if!bool {
		result = 1
	}

	// Printing the result to the console
	fmt.Println(result)
}

