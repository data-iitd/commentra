package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin) // Creating a new buffered reader for input

	// Reading the first line of input which contains the number of test cases
	input, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(strings.TrimSpace(input)) // Parsing the number of test cases

	// Checking if the number of test cases is equal to 1
	if n == 1 {
		// If yes, printing "Hello World" as output
		fmt.Println("Hello World")
	} else {
		// If not, reading the next line of input which contains two integers
		input, _ := reader.ReadString('\n')
		strs := strings.Fields(strings.TrimSpace(input)) // Splitting the input into fields
		num1, _ := strconv.Atoi(strs[0]) // Storing the first integer in a variable 'num1'
		num2, _ := strconv.Atoi(strs[1]) // Storing the second integer in a variable 'num2'

		// Printing the sum of the two integers as output
		fmt.Println(num1 + num2)
	}
}

// Note: In Go, there is no need for a close function for the buffered reader
// as it is automatically managed by the garbage collector.
// <END-OF-CODE>
