
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Create a new scanner to read input from the standard input
	scanner := bufio.NewScanner(os.Stdin)

	// Use the scanner to read two integers from the standard input and store them in n and m variables
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	m, _ := strconv.Atoi(scanner.Text())

	// Calculate the product of (n - 1) and (m - 1) and store the result in the variable result
	result := (n - 1) * (m - 1)

	// Use the fmt package to print the result to the standard output
	fmt.Println(result)

	// Flush the output buffer to ensure that all the data is written to the standard output before the program terminates
	fmt.Println()

	// Indicate that the program has run successfully and terminate it
}

