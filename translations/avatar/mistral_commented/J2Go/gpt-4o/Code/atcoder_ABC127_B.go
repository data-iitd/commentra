package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Creating a buffered reader for reading input
	reader := bufio.NewReader(os.Stdin)

	// Reading input variables from the user
	r, _ := readInt(reader) // Reading the first integer 'r' from the user
	d, _ := readInt(reader) // Reading the second integer 'd' from the user
	x, _ := readLong(reader) // Reading the long integer 'x' from the user

	// Running the loop for 10 iterations
	for i := 0; i < 10; i++ {
		// Multiplying 'r' with 'x' and subtracting 'd' from it
		x = r*x - d

		// Writing the result to the output stream
		fmt.Println(x)
	}
}

// Function to read an integer from the input
func readInt(reader *bufio.Reader) (int, error) {
	input, err := reader.ReadString('\n')
	if err != nil {
		return 0, err
	}
	return strconv.Atoi(input[:len(input)-1]) // Convert string to int
}

// Function to read a long integer (int64) from the input
func readLong(reader *bufio.Reader) (int64, error) {
	input, err := reader.ReadString('\n')
	if err != nil {
		return 0, err
	}
	return strconv.ParseInt(input[:len(input)-1], 10, 64) // Convert string to int64
}
