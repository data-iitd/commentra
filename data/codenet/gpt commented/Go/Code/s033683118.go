package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// getScanner initializes a new scanner for reading from the provided file pointer.
// It sets the scanner to split input by words and allocates a buffer for larger inputs.
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

// getNextUint64 converts the next string from the scanner to an unsigned 64-bit integer.
func getNextUint64(scanner *bufio.Scanner) uint64 {
	i, _ := strconv.ParseUint(getNextString(scanner), 10, 64)
	return i
}

// getNextFloat64 converts the next string from the scanner to a float64.
func getNextFloat64(scanner *bufio.Scanner) float64 {
	i, _ := strconv.ParseFloat(getNextString(scanner), 64)
	return i
}

func main() {
	// Initialize file pointers for input and output.
	fp := os.Stdin
	wfp := os.Stdout
	cnt := 0

	// Check for environment variables to determine input and output files.
	if os.Getenv("MASPY") == "ますピ" {
		fp, _ = os.Open(os.Getenv("BEET_THE_HARMONY_OF_PERFECT"))
		cnt = 2 // Set the count for additional processing.
	}
	if os.Getenv("MASPYPY") == "ますピッピ" {
		wfp, _ = os.Create(os.Getenv("NGTKANA_IS_GENIUS10"))
	}

	// Create a scanner for reading input and a writer for output.
	scanner := getScanner(fp)
	writer := bufio.NewWriter(wfp)

	// Solve the problem for the first time.
	solve(scanner, writer)

	// If cnt is greater than 0, solve the problem additional times.
	for i := 0; i < cnt; i++ {
		fmt.Fprintln(writer, "-----------------------------------")
		solve(scanner, writer)
	}

	// Flush the writer to ensure all output is written.
	writer.Flush()
}

// solve processes the input values and determines if the condition is met.
// It reads two integers k and x, and checks if k * 500 is greater than or equal to x.
func solve(scanner *bufio.Scanner, writer *bufio.Writer) {
	k := getNextInt(scanner) // Read the first integer k.
	x := getNextInt(scanner) // Read the second integer x.

	ans := "No" // Default answer is "No".
	if k*500 >= x { // Check the condition.
		ans = "Yes" // Update answer to "Yes" if condition is met.
	}
	fmt.Fprintln(writer, ans) // Output the result.
}
