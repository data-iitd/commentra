
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Initialize a new scanner for reading input from stdin
var sc = bufio.NewScanner(os.Stdin)

// Function to read an integer from standard input
func readInt() int {
	// Read a word from standard input
	sc.Scan()
	// Convert the read word to an integer
	i, err := strconv.Atoi(sc.Text())
	// If the conversion fails, panic with an error message
	if err != nil {
		panic(err)
	}
	// Return the integer value
	return i
}

// Function to read a float64 from standard input
func readFloat64() float64 {
	// Read a word from standard input
	sc.Scan()
	// Convert the read word to a float64
	f, err := strconv.ParseFloat(sc.Text(), 64)
	// If the conversion fails, panic with an error message
	if err != nil {
		panic(err)
	}
	// Return the float64 value
	return f
}

// Function to read a string from standard input
func readString() string {
	// Read a word from standard input
	sc.Scan()
	// Return the read word as a string
	return sc.Text()
}

// Main function
func main() {
	// Set the scanner to read words as input
	sc.Split(bufio.ScanWords)
	// Read the number of elements n and the number of queries m from standard input
	n, m := readInt(), readInt()
	// Allocate an array a of size n
	a := make([]int, n)
	// Initialize a variable sum to keep track of the sum of elements in the array
	sum := 0
	// Process each query
	for i := 0; i < m; i++ {
		// Read an integer from standard input and add it to the array a
		a[i] = readInt()
		// Add the current element to the sum
		sum += a[i]
		// Check if the sum is greater than the size of the array
		if sum > n {
			// If so, print -1 and exit the program
			fmt.Println("-1")
			return
		}
	}
	// Print the result, which is the difference between the size of the array and the sum of its elements
	fmt.Println(n - sum)
}

