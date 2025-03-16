package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type FastReader struct {
	scanner *bufio.Scanner
}

func NewFastReader() *FastReader {
	return &FastReader{scanner: bufio.NewScanner(os.Stdin)}
}

func (fr *FastReader) Next() string {
	fr.scanner.Scan()
	return fr.scanner.Text()
}

func (fr *FastReader) NextInt() int {
	num, _ := strconv.Atoi(fr.Next())
	return num
}

func (fr *FastReader) NextLine() string {
	return fr.Next()
}

var prevWinner int

func solve(fr *FastReader) {
	t := fr.NextInt() // Reading the number of test cases
	arr := make([]int, t) // Creating an integer slice of size 't' to store the input

	for i := 0; i < t; i++ { // Iterating through the slice
		arr[i] = fr.NextInt() // Reading each element

		if arr[i] == 1 { // Checking if the current element is 1
			if prevWinner == 0 { // If the previous winner was 0
				prevWinner = 2 // Update the 'prevWinner' variable to 2
			}

			if (arr[i]-1)%2 == 0 { // Checking the parity of the current element's index
				if prevWinner == 0 {
					fmt.Println(2) // Printing the output based on the 'prevWinner' value
				} else {
					fmt.Println(1)
				}
				prevWinner = 1
			}
		}
	}
}

func main() {
	fr := NewFastReader() // Creating an instance of FastReader
	prevWinner = 0 // Initializing the 'prevWinner' variable to 0

	t := 1 // Initializing the test case counter
	for t > 0 { // Running the solution process for all test cases
		solve(fr)
		t--
	}
}

// <END-OF-CODE>
