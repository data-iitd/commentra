package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin) // Creating a new scanner for reading input
	scanner.Scan() // Reading the first line
	n, _ := strconv.Atoi(scanner.Text()) // Parsing the number of test cases

	max := 0 // Initializing the maximum sum to zero

	for i := 0; i < n; i++ { // Processing each test case
		scanner.Scan() // Reading the next line
		line := scanner.Text() // Getting the line
		tokens := strings.Fields(line) // Splitting the line into tokens

		f, _ := strconv.Atoi(tokens[0]) // Parsing the first number
		t, _ := strconv.Atoi(tokens[1]) // Parsing the second number

		if max < f+t { // Checking if the sum of the current numbers is greater than the current maximum sum
			max = f + t // Updating the maximum sum if it is
		}
	}

	fmt.Println(max) // Writing the maximum sum to the output
}

// <END-OF-CODE>
