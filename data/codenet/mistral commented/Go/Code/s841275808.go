
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"sort"
)

func main() {
	// Initialize a scanner to read input from standard input
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	// Read the number of elements in the array from the input
	N := ScanInt(scanner)
	// Allocate memory for two arrays X and Y of size N
	X := make([]int, N)
	Y := make([]int, N)

	// Read N integers from the input and store them in X and Y arrays
	for i := 0; i < N; i++ {
		X[i] = ScanInt(scanner)
		// Store the current element of X in Y array for sorting
		Y[i] = X[i]
	}

	// Sort the Y array in ascending order
	sort.Sort(sort.IntSlice(Y))

	// Find the median of Y array
	m1 := Y[N/2 - 1]
	m2 := Y[N/2]

	// Iterate through each element of X array and print the corresponding median value
	for i := 0; i < N; i++ {
		if X[i] <= m1 {
			// If X[i] is smaller than m1, print m2 as the answer
			fmt.Println(m2)
		} else {
			// If X[i] is greater than m1, print m1 as the answer
			fmt.Println(m1)
		}
	}
}

// Function to read an integer from the input
func ScanInt(scanner *bufio.Scanner) int {
	// Scan the next token as a word
	scanner.Scan()
	// Convert the word to an integer and return it
	i, _ := strconv.Atoi(scanner.Text())
	return i
}

// Function to read a float64 from the input
func ScanFloat64(scanner *bufio.Scanner) float64 {
	// Scan the next token as a word
	scanner.Scan()
	// Convert the word to a float64 and return it
	f, _ := strconv.ParseFloat(scanner.Text(), 64)
	return f
}

// Function to read a text from the input
func ScanText(scanner *bufio.Scanner) string {
	// Scan the next token as a word
	scanner.Scan()
	// Return the scanned word as a text
	return scanner.Text()
}

// Function to find the maximum of two integers
func Max(a, b int) int {
	// If a is smaller than b, return b
	if a < b {
		return b
	}
	// Otherwise, return a
	return a
}

// Function to find the minimum of two integers
func Min(a, b int) int {
	// If a is greater than b, return b
	if a > b {
		return b
	}
	// Otherwise, return a
	return a
}

// Function to find the absolute value of an integer
func Abs(a int) int {
	// If a is negative, return the negative of a
	if a < 0 {
		return -a
	}
	// Otherwise, return a
	return a
}
