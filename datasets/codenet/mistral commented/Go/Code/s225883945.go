
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Initialize scanner for reading input from stdin
var sc = bufio.NewScanner(os.Stdin)

// Function to read a single word from the input
func next() string {
	sc.Scan()
	return sc.Text()
}

// Function to read an integer from the input
func nextInt() int {
	sc.Scan()
	// Convert the input string to an integer
	i, _ := strconv.Atoi(sc.Text())
	return i
}

// Function to read a float64 from the input
func nextFloat64() float64 {
	f, _ := strconv.ParseFloat(next(), 64)
	return f
}

// Function to read n integers from the input
func nextInts(n int) []int {
	slice := make([]int, n)
	// Read n integers and store them in the slice
	for i := 0; i < n; i++ {
		slice[i] = nextInt()
	}
	return slice
}

// Main function
func main() {
	// Set scanner to read words as input
	sc.Split(bufio.ScanWords)

	// Read number of elements n and the sum of elements k from the input
	n, k := nextInt(), nextInt()

	// Initialize a slice of size n to store the input elements
	a := make([]int, n)

	// Assign a default value of 0 to the first element of the slice to avoid unused variable error
	a[0] = 0

	// Initialize sum and answer variables
	sum, ans := 0, 1

	// Use a loop to find the number of times k can be subtracted from n to reach a non-negative value
	for sum < n {
		// Subtract 1 from sum and add k to find the next index to check
		sum = sum - 1 + k
		// Increment the answer variable for each iteration
		ans++
	}

	// Print the answer
	fmt.Println(ans)

	// End of code
}