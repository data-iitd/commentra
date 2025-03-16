
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// FastReader class to handle fast input
type FastReader struct {
	br   *bufio.Reader
	st   *strings.Reader
	temp []byte
}

// Constructor to initialize BufferedReader
func NewFastReader() *FastReader {
	return &FastReader{br: bufio.NewReader(os.Stdin), st: nil, temp: nil}
}

// Method to read the next token from input
func (f *FastReader) next() string {
	// Read new line if no tokens are available
	for f.st == nil || !f.st.Scan() {
		f.temp, _ = f.br.ReadBytes('\n')
		f.st = strings.NewReader(string(f.temp))
	}
	return f.st.Text()
}

// Method to read the next integer from input
func (f *FastReader) nextInt() int {
	return int(f.nextInt64())
}

// Method to read the next long from input
func (f *FastReader) nextInt64() int64 {
	return int64(strconv.ParseInt(f.next(), 10, 64))
}

// Method to read the next double from input
func (f *FastReader) nextFloat64() float64 {
	return float64(strconv.ParseFloat(f.next(), 64))
}

// Method to read the next line from input
func (f *FastReader) nextLine() string {
	str := ""
	for f.st == nil || !f.st.Scan() {
		f.temp, _ = f.br.ReadBytes('\n')
		f.st = strings.NewReader(string(f.temp))
	}
	str, _ = f.st.ReadString('\n')
	return str
}

// Create an instance of FastReader for input
var scan = NewFastReader()

func main() {
	t := scan.nextInt() // Number of test cases (currently set to 1)
	for t > 0 {
		t--
		solve() // Call the solve method for processing
	}
}

func solve() {
	// Read the number of elements in the array
	t := scan.nextInt()
	arr := make([]int, t)

	// Populate the array with input values
	for i := 0; i < len(arr); i++ {
		arr[i] = scan.nextInt()
	}

	prevWinner := 0 // Variable to track the previous winner

	// Iterate through the array to determine the winner for each element
	for i := 0; i < len(arr); i++ {
		// Check if the current element is 1
		if arr[i] == 1 {
			// If the previous winner is 0, set the previous winner to 2
			if prevWinner == 0 {
				prevWinner = 2
			}
		}

		// Determine the winner based on the previous winner and the current element
		if prevWinner == 2 || prevWinner == 0 {
			// If the previous winner is 2 or 0, check the parity of (arr[i] - 1)
			if (arr[i]-1)%2 == 0 {
				fmt.Println(2) // Print winner 2
				prevWinner = 2 // Update previous winner
			} else {
				fmt.Println(1) // Print winner 1
				prevWinner = 1 // Update previous winner
			}
		} else {
			// If the previous winner is 1, check the parity of (arr[i] - 1)
			if (arr[i]-1)%2 == 0 {
				fmt.Println(1) // Print winner 1
				prevWinner = 1 // Update previous winner
			} else {
				fmt.Println(2) // Print winner 2
				prevWinner = 2 // Update previous winner
			}
		}
	}
}

// 