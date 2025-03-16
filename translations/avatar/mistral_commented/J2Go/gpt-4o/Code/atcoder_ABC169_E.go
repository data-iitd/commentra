package main

import (
	"bufio" // Importing bufio for buffered I/O
	"fmt"   // Importing fmt for formatted I/O
	"os"    // Importing os for standard input/output
	"sort"  // Importing sort for sorting slices
)

func main() {
	num := 998244353 // Initializing a variable 'num' with a value

	reader := bufio.NewReader(os.Stdin) // Creating a buffered reader to read input from standard input
	writer := bufio.NewWriter(os.Stdout) // Creating a buffered writer to write output to standard output
	defer writer.Flush()                   // Ensuring the writer flushes the output at the end

	var n int
	fmt.Fscanln(reader, &n) // Reading the number of test cases from the input

	ai := make([]int, 0, n) // Creating a slice to store the first array elements
	bi := make([]int, 0, n) // Creating a slice to store the second array elements

	for i := 0; i < n; i++ { // Iterating through the test cases
		var a, b int
		fmt.Fscan(reader, &a, &b) // Reading two integers from the input
		ai = append(ai, a)        // Adding the first array element to the slice
		bi = append(bi, b)        // Adding the second array element to the slice
	}

	// Sorting the slices in ascending order
	sort.Ints(ai)
	sort.Ints(bi)

	if n%2 == 1 { // Checking if the number of test cases is odd
		midIndex := len(bi) / 2
		result := bi[midIndex] - ai[midIndex] + 1 // Calculating the answer for odd number of test cases
		fmt.Fprintln(writer, result)               // Printing the result
	} else {
		midIndex := len(ai) / 2
		b := float64(ai[midIndex]+ai[midIndex-1]) / 2 // Calculating the average of the middle two elements of the first slice
		c := float64(bi[midIndex]+bi[midIndex-1]) / 2 // Calculating the average of the middle two elements of the second slice
		result := int(2*(c-b) + 1)                    // Calculating the answer for even number of test cases
		fmt.Fprintln(writer, result)                   // Printing the result
	}
}

// <END-OF-CODE>
