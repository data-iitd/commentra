package main

import (
	"bufio" // Importing bufio for buffered I/O
	"fmt"   // Importing fmt for formatted I/O
	"os"    // Importing os for operating system functionalities
	"strconv" // Importing strconv for string conversions
	"strings" // Importing strings for string manipulation
)

func main() {
	// Create a new scanner to read input from standard input
	s := bufio.NewScanner(os.Stdin)

	// Read the first line of input (not used)
	s.Scan()
	// Read the second line of input which contains space-separated integers
	s.Scan()
	ds := s.Text()

	// Split the input string into a slice of strings
	dd := strings.Split(ds, " ")
	// Create a slice of integers to hold the converted values
	dn := make([]int, len(dd))
	
	// Convert each string in the slice to an integer
	for i, d := range dd {
		dn[i], _ = strconv.Atoi(d) // Ignore error for simplicity
	}

	// Initialize a variable to hold the sum of products
	sum := 0
	// Calculate the sum of products of all unique pairs of integers
	for i := 0; i < len(dn); i++ {
		for j := i + 1; j < len(dn); j++ {
			sum += dn[i] * dn[j] // Multiply the pair and add to sum
		}
	}

	// Output the final sum of products
	fmt.Println(sum)
}
