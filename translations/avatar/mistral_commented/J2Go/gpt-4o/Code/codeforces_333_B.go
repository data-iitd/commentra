package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Main function declaration

	reader := bufio.NewReader(os.Stdin) // Creating a buffered reader for reading input
	writer := bufio.NewWriter(os.Stdout) // Creating a buffered writer for writing output
	defer writer.Flush()                   // Ensuring the writer flushes at the end

	n, _ := nextInt(reader) // Reading the number of rows in the grid
	m, _ := nextInt(reader) // Reading the number of banned cells

	bannedRows := make(map[int]struct{}) // Creating a map to store banned rows
	bannedCols := make(map[int]struct{}) // Creating a map to store banned columns

	for i := 0; i < m; i++ {
		// Reading banned cells and adding them to the respective maps

		r, _ := nextInt(reader)
		if r > 1 && r < n {
			bannedRows[r] = struct{}{} // Adding banned row
		}

		c, _ := nextInt(reader)
		if c > 1 && c < n {
			bannedCols[c] = struct{}{} // Adding banned column
		}
	}

	answer := (n - 2) * 2 // Initializing answer as the total number of cells in the grid minus the banned cells
	answer -= len(bannedRows) // Subtracting the number of banned rows
	answer -= len(bannedCols) // Subtracting the number of banned columns

	if n%2 != 0 {
		// Special case when the number of rows is odd

		mid := (n + 1) / 2
		if _, ok := bannedRows[mid]; !ok && _, ok := bannedCols[mid]; !ok {
			// If the middle cell is not banned, decrement the answer
			answer--
		}
	}

	fmt.Fprintln(writer, answer) // Writing the answer to the output stream
}

// nextInt reads the next integer from the input
func nextInt(reader *bufio.Reader) (int, error) {
	line, err := reader.ReadString('\n') // Reading the next line
	if err != nil {
		return 0, err // Returning error if reading fails
	}
	return strconv.Atoi(line[:len(line)-1]) // Converting the string to an integer and returning it
}

// nextLong reads the next long integer from the input
func nextLong(reader *bufio.Reader) (int64, error) {
	line, err := reader.ReadString('\n') // Reading the next line
	if err != nil {
		return 0, err // Returning error if reading fails
	}
	return strconv.ParseInt(line[:len(line)-1], 10, 64) // Converting the string to a long integer and returning it
}

// nextDouble reads the next double from the input
func nextDouble(reader *bufio.Reader) (float64, error) {
	line, err := reader.ReadString('\n') // Reading the next line
	if err != nil {
		return 0, err // Returning error if reading fails
	}
	return strconv.ParseFloat(line[:len(line)-1], 64) // Converting the string to a double and returning it
}

// nextLine reads the next line from the input
func nextLine(reader *bufio.Reader) (string, error) {
	line, err := reader.ReadString('\n') // Reading the next line
	if err != nil {
		return "", err // Returning error if reading fails
	}
	return line[:len(line)-1], nil // Returning the next line
}

// <END-OF-CODE>
