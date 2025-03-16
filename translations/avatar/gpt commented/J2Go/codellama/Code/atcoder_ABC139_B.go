package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Create a Scanner object to read input from the console
	sc := bufio.NewScanner(os.Stdin)

	// Read two integers A and B from the input
	var A, B int
	fmt.Scan(&A, &B)

	// Initialize variables to hold the remainder and the result
	var amari, result int

	// Calculate the initial result based on the formula (B - 1) / (A - 1)
	result = (B - 1) / (A - 1)

	// Calculate the remainder when (B - 1) is divided by (A - 1)
	amari = (B - 1) % (A - 1)

	// If there is a remainder, increment the result by 1
	if amari != 0 {
		result += 1
	}

	// Create a PrintWriter object to output the result
	out := bufio.NewWriter(os.Stdout)

	// Print the final result to the console
	fmt.Fprintln(out, result)

	// Close the Scanner to free resources
	sc.Close()

	// Flush the PrintWriter to ensure all output is written
	out.Flush()
}

