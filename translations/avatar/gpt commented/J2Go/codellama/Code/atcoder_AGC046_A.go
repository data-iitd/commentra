package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a FastReader object to read input efficiently
	sc := FastReader{}
	// Create a PrintWriter object to output results
	pw := PrintWriter{}

	// Read an integer input from the user
	x := sc.nextInt()
	// Initialize a counter to keep track of the number of rotations
	count := 0
	// Store the original value of x for later use
	tmp := x
	// Reset x to 0 for the rotation calculation
	x = 0

	// Loop until x completes a full rotation (360 degrees)
	for x != 360 {
		// Increment x by the original input value
		x = x + tmp
		// If x exceeds 360, wrap it around by subtracting 360
		if x > 360 {
			x = x - 360
		}
		// Increment the count of rotations
		count++
	}

	// Output the total number of rotations needed to reach 360 degrees
	fmt.Println(count)
}

// FastReader class for efficient input reading
type FastReader struct{}

// Method to read the next token as a String
func (sc *FastReader) next() string {
	// Continue reading until there are more tokens available
	for sc.st == nil || !sc.st.Scan() {
		sc.st = bufio.NewScanner(os.Stdin)
		sc.st.Split(bufio.ScanWords)
	}
	// Return the next token
	return sc.st.Text()
}

// Method to read the next token as an integer
func (sc *FastReader) nextInt() int {
	return int(sc.nextInt64())
}

// Method to read the next token as a long
func (sc *FastReader) nextInt64() int64 {
	return int64(sc.nextInt64())
}

// Method to read the next token as a double
func (sc *FastReader) nextDouble() float64 {
	return float64(sc.nextDouble())
}

// Method to read the next line as a String
func (sc *FastReader) nextLine() string {
	str := ""
	for sc.st == nil || !sc.st.Scan() {
		sc.st = bufio.NewScanner(os.Stdin)
		sc.st.Split(bufio.ScanLines)
	}
	str = sc.st.Text()
	return str
}

// PrintWriter class for efficient output
type PrintWriter struct{}

// Method to output the result
func (pw *PrintWriter) println(x int) {
	fmt.Println(x)
}

// END-OF-CODE
