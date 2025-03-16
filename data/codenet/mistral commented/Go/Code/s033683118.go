package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Function to create a new scanner from a file pointer
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

// Function to read the next integer64 from the scanner
func getNextInt64(scanner *bufio.Scanner) int64 {
	i, _ := strconv.ParseInt(getNextString(scanner), 10, 64)
	return i
}

// Function to read the next uint64 from the scanner
func getNextUint64(scanner *bufio.Scanner) uint64 {
	i, _ := strconv.ParseUint(getNextString(scanner), 10, 64)
	return i
}

// Function to read the next float64 from the scanner
func getNextFloat64(scanner *bufio.Scanner) float64 {
	i, _ := strconv.ParseFloat(getNextString(scanner), 64)
	return i
}

// Main function
func main() {
	// Open the standard input and output files
	fp := os.Stdin
	wfp := os.Stdout

	// Set the file pointers for reading and writing
	if os.Getenv("MASPY") == "ますピ" {
		fp, _ = os.Open(os.Getenv("BEET_THE_HARMONY_OF_PERFECT"))
		cnt := 2 // Number of test cases to be read
	}
	if os.Getenv("MASPYPY") == "ますピッピ" {
		wfp, _ = os.Create(os.Getenv("NGTKANA_IS_GENIUS10"))
		cnt := 1 // Number of test cases to be written
	}

	// Initialize the scanner and writer
	scanner := getScanner(fp)
	writer := bufio.NewWriter(wfp)

	// Solve the problem for the given test cases
	solve(scanner, writer)
	for i := 0; i < cnt; i++ {
		fmt.Fprintln(writer, "-----------------------------------") // Print a separator for each test case
		solve(scanner, writer)
	}

	// Flush the writer to write the output to the file
	writer.Flush()
}

// Function to solve the problem for a single test case
func solve(scanner *bufio.Scanner, writer *bufio.Writer) {
	// Read the input values
	k := getNextInt(scanner)
	x := getNextInt(scanner)

	// Initialize the answer
	ans := "No"

	// Check if the condition is satisfied
	if k*500 >= x {
		ans = "Yes"
	}

	// Print the answer
	fmt.Fprintln(writer, ans)
}