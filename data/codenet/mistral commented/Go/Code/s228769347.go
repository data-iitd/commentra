// Package main is the entry point of the program
package main

import (
	// Importing required packages
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

func getScanner(fp *os.File) *bufio.Scanner {
	// Function to initialize a new scanner for reading input
	scanner := bufio.NewScanner(fp)
	scanner.Split(bufio.ScanWords)
	scanner.Buffer(make([]byte, 500001), 500000) // Buffer size for efficient reading
	return scanner
}

func getNextString(scanner *bufio.Scanner) string {
	// Function to read the next word as a string
	scanner.Scan()
	return scanner.Text()
}

func getNextInt(scanner *bufio.Scanner) int {
	// Function to read the next integer from the input
	i, _ := strconv.Atoi(getNextString(scanner))
	return i
}

func getNextInt64(scanner *bufio.Scanner) int64 {
	// Function to read the next integer64 from the input
	i, _ := strconv.ParseInt(getNextString(scanner), 10, 64)
	return i
}

func getNextUint64(scanner *bufio.Scanner) uint64 {
	// Function to read the next uint64 from the input
	i, _ := strconv.ParseUint(getNextString(scanner), 10, 64)
	return i
}

func getNextFloat64(scanner *bufio.Scanner) float64 {
	// Function to read the next float64 from the input
	i, _ := strconv.ParseFloat(getNextString(scanner), 64)
	return i
}

// Main function to solve the problem
func main() {
	// Initializing standard input and output file pointers
	fp := os.Stdin
	wfp := os.Stdout

	// If input file and output file are provided as command line arguments
	if len(os.Args) > 1 {
		// Open the input file
		fp, _ = os.Open(os.Args[1])

		// If output file is provided, create it
		if len(os.Args) > 2 {
			wfp, _ = os.Create(os.Args[2])
		}
	}

	// Initialize a new scanner for reading input
	scanner := getScanner(fp)
	writer := bufio.NewWriter(wfp)

	// Read the number of elements in the array
	n := getNextInt(scanner)

	// Initialize a slice of length n to store the elements
	ll := make([]int, n)

	// Read the elements of the array
	for i := 0; i < n; i++ {
		ll[i] = getNextInt(scanner)
	}

	// Sort the slice in ascending order
	sort.Ints(ll)

	// Initialize the answer variable to 0
	ans := 0

	// Iterate through all possible pairs of elements
	for i := 0; i < n-2; i++ {
		// Iterate through all possible right pointers
		for j := i + 1; j < n-1; j++ {
			// Initialize the left and right pointers for binary search
			l := j + 1
			r := n

			// Binary search to find the index of the element greater than the sum of the current pair
			for l < r {
				m := (l + r) >> 1
				if ll[m] < ll[i]+ll[j] {
					l = m + 1
					continue
				}
				r = m
			}

			// Update the answer variable
			ans += l - (j + 1)
		}
	}

	// Write the answer to the output file
	fmt.Fprintln(writer, ans)

	// Flush the writer buffer
	writer.Flush()
}

// "