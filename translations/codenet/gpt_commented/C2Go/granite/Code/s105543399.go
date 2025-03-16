
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Declare variables
	var n, a, m, M, c, b, i int64
	var err error
	var reader *bufio.Reader = bufio.NewReader(os.Stdin)

	// Initialize cumulative sum and set initial min and max values
	c = 0 // Cumulative sum of the numbers
	m = 100000000 // Initialize minimum value to a large number
	M = -100000000 // Initialize maximum value to a small number

	// Read the number of elements
	n, err = strconv.ParseInt(read(reader), 10, 64)
	checkError(err)

	// Loop through each element to read and process
	for i = 1; i <= n; i++ {
		// Read the current number
		a, err = strconv.ParseInt(read(reader), 10, 64)
		checkError(err)

		// Update maximum value if the current number is greater
		if a > M {
			M = a
		}

		// Update minimum value if the current number is smaller
		if a < m {
			m = a
		}

		// Add the current number to the cumulative sum
		c = c + a
	}

	// Print the minimum, maximum, and cumulative sum
	fmt.Printf("%d %d %d\n", m, M, c)
}

func read(reader *bufio.Reader) string {
	var s string
	var err error
	s, err = reader.ReadString('\n')
	s = s[:len(s)-1]
	checkError(err)
	return s
}

func checkError(err error) {
	if err!= nil {
		panic(err)
	}
}

