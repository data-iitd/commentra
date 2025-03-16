
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Function to create a new bufio.Scanner from a file pointer
func getScanner(fp *os.File) *bufio.Scanner {
	scanner := bufio.NewScanner(fp)
	scanner.Split(bufio.ScanWords)
	scanner.Buffer(make([]byte, 500001), 500000) // Buffer size for efficient reading
	return scanner
}

// Function to read the next string from the scanner
func getNextString(scanner *bufio.Scanner) string {
	scanner.Scan()
	return scanner.Text()
}

// Function to read the next integer from the scanner
func getNextInt(scanner *bufio.Scanner) int {
	i, _ := strconv.Atoi(getNextString(scanner))
	return i
}

// Function to read the next int64 from the scanner
func getNextInt64(scanner *bufio.Scanner) int64 {
	i, _ := strconv.ParseInt(getNextString(scanner), 10, 64)
	return i
}

// Main function
func main() {
	// Open the standard input as a file
	fp := os.Stdin
	// If there is an argument, open the file with that name instead
	if len(os.Args) > 1 {
		fp, _ = os.Open(os.Args[1])
	}

	// Create a new bufio.Scanner from the file pointer
	scanner := getScanner(fp)

	// Create a new bufio.Writer for output
	writer := bufio.NewWriter(os.Stdout)

	// Read the first integer from the input
	n := getNextInt(scanner)

	// Initialize an array 'aa' of size 'n+2'
	aa := make([]int, n+2)
	// Initialize a variable 'sum' to store the sum of absolute differences between consecutive elements
	sum := 0

	// Iterate through the array 'aa' and calculate the sum of absolute differences between consecutive elements
	for i := 0; i < n; i++ {
		// Read the next integer from the scanner and store it in 'aa[i+1]'
		aa[i+1] = getNextInt(scanner)
		// Calculate the absolute difference between the current and previous elements and add it to the sum
		sum += absint(aa[i+1] - aa[i])
	}
	// Calculate the absolute difference between the last two elements and add it to the sum
	sum += absint(aa[n+1] - aa[n])

	// Iterate through the array 'aa' and print the answer for each subarray
	for i := 1; i < n+1; i++ {
		// Calculate the answer for the subarray from 'aa[i]' to 'aa[i+1]'
		ans := sum - absint(aa[i+1]-aa[i]) - absint(aa[i]-aa[i-1]) + absint(aa[i+1]-aa[i-1])
		// Write the answer to the output writer
		fmt.Fprintln(writer, ans)
	}

	// Flush the buffer to write all the data to the output
	writer.Flush()
}

// Function to calculate the absolute value of an integer
func absint(a int) int {
	if a < 0 {
		return -a
	}
	return a
}

