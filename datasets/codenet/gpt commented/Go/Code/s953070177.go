package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// getScanner initializes a new scanner for reading from the provided file pointer.
// It sets the scanner to split input by words and allocates a buffer for large inputs.
func getScanner(fp *os.File) *bufio.Scanner {
	scanner := bufio.NewScanner(fp)
	scanner.Split(bufio.ScanWords)
	scanner.Buffer(make([]byte, 500001), 500000)
	return scanner
}

// getNextString retrieves the next string from the scanner.
func getNextString(scanner *bufio.Scanner) string {
	scanner.Scan()
	return scanner.Text()
}

// getNextInt converts the next string from the scanner to an integer.
func getNextInt(scanner *bufio.Scanner) int {
	i, _ := strconv.Atoi(getNextString(scanner))
	return i
}

// getNextInt64 converts the next string from the scanner to a 64-bit integer.
func getNextInt64(scanner *bufio.Scanner) int64 {
	i, _ := strconv.ParseInt(getNextString(scanner), 10, 64)
	return i
}

func main() {
	// Determine the input source: standard input or a file specified as a command-line argument.
	fp := os.Stdin
	if len(os.Args) > 1 {
		fp, _ = os.Open(os.Args[1])
	}

	// Initialize the scanner for reading input.
	scanner := getScanner(fp)

	// Create a buffered writer for output.
	writer := bufio.NewWriter(os.Stdout)

	// Read the number of elements from the input.
	n := getNextInt(scanner)

	// Initialize an array to hold the elements and a variable to store the total sum of absolute differences.
	aa := make([]int, n+2)
	sum := 0

	// Read the elements into the array and calculate the total sum of absolute differences between consecutive elements.
	for i := 0; i < n; i++ {
		aa[i+1] = getNextInt(scanner)
		sum += absint(aa[i+1] - aa[i])
	}
	// Include the difference between the last element and the element before it.
	sum += absint(aa[n+1] - aa[n])

	// Calculate and print the result for each element.
	for i := 1; i < n+1; i++ {
		// Calculate the new sum of absolute differences if the i-th element is removed.
		ans := sum - absint(aa[i+1]-aa[i]) - absint(aa[i]-aa[i-1]) + absint(aa[i+1]-aa[i-1])
		fmt.Fprintln(writer, ans) // Output the result for the current element.
	}

	// Flush the buffered writer to ensure all output is written.
	writer.Flush()
}

// absint returns the absolute value of an integer.
func absint(a int) int {
	if a < 0 {
		return -a
	}
	return a
}
