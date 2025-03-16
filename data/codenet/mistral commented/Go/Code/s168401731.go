
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// getScanner initializes and returns a new bufio.Scanner from the given file pointer
func getScanner(fp *os.File) *bufio.Scanner {
	scanner := bufio.NewScanner(fp)
	scanner.Split(bufio.ScanWords)
	scanner.Buffer(make([]byte, 500001), 500000) // buffer size
	return scanner
}

// getNextString reads and returns the next word as a string from the scanner
func getNextString(scanner *bufio.Scanner) string {
	scanner.Scan()
	return scanner.Text()
}

// getNextInt reads and converts the next integer from the scanner to an int
func getNextInt(scanner *bufio.Scanner) int {
	i, _ := strconv.Atoi(getNextString(scanner))
	return i
}

// getNextInt64 reads and converts the next integer from the scanner to an int64
func getNextInt64(scanner *bufio.Scanner) int64 {
	i, _ := strconv.ParseInt(getNextString(scanner), 10, 64)
	return i
}

// getNextUint64 reads and converts the next unsigned integer from the scanner to a uint64
func getNextUint64(scanner *bufio.Scanner) uint64 {
	i, _ := strconv.ParseUint(getNextString(scanner), 10, 64)
	return i
}

// getNextFloat64 reads and converts the next floating-point number from the scanner to a float64
func getNextFloat64(scanner *bufio.Scanner) float64 {
	i, _ := strconv.ParseFloat(getNextString(scanner), 64)
	return i
}

// main function is the entry point of the program
func main() {
	// open standard input as default file if no arguments are provided
	fp := os.Stdin
	// open output file if provided as an argument
	wfp := os.Stdout
	if len(os.Args) > 1 {
		fp, _ = os.Open(os.Args[1])
		// create output file if provided as an argument
		if len(os.Args) > 2 {
			wfp, _ = os.Create(os.Args[2])
		}
	}

	// initialize scanner and writer
	scanner := getScanner(fp)
	writer := bufio.NewWriter(wfp)

	// read the first integer from the input
	n := getNextInt(scanner)

	// initialize answer variable
	ans := "second"
	// iterate through the input integers
	for i := 0; i < n; i++ {
		// read the next integer from the input
		a := getNextInt(scanner)
		// check if the current integer is odd
		if a%2 == 1 {
			// update the answer if an odd integer is found
			ans = "first"
			// exit the loop if only one odd integer is found
			break
		}
	}
	// write the answer to the output
	fmt.Fprintln(writer, ans)
	// flush the writer buffer
	writer.Flush()

