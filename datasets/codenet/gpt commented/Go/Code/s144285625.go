package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

// Create a new scanner to read input from standard input
var sc = bufio.NewScanner(os.Stdin)

func main() {
	// Set the scanner to split input by whitespace
	sc.Split(bufio.ScanWords)

	// Read the number of groups of three integers
	n := nextInt()

	// Initialize a slice to hold 3*n integers
	ar := make([]int, 3*n)

	// Populate the slice with integers from input
	for i := range ar {
		ar[i] = nextInt()
	}

	// Sort the slice of integers in ascending order
	sort.Ints(ar)

	// Initialize a variable to hold the sum of selected integers
	sum := 0

	// Calculate the sum of the second largest integer from each group of three
	for i := 0; i < n; i++ {
		sum += ar[3*n-(i+1)*2] // Select the second largest integer from the sorted slice
	}

	// Print the final computed sum
	fmt.Println(sum)
}

// nextInt reads the next integer from the input
func nextInt() int {
	sc.Scan() // Read the next token from input
	i, _ := strconv.Atoi(sc.Text()) // Convert the token to an integer
	return i // Return the integer value
}
