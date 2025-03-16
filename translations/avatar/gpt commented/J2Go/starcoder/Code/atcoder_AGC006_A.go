package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Define a constant for the maximum size of the arrays
const N = 200 + 10

// Array to store the failure function values
var f [N]int

// Array to store the concatenated strings
var b [N]byte

// Function to compute the failure function for the KMP algorithm
func getFail(b []byte, m int) {
	j := 0
	f[0] = f[1] = 0

	// Loop through the string to fill the failure function
	for i := 2; i <= m; i++ {
		// Adjust j until we find a match or j becomes 0
		for j > 0 && b[j + 1]!= b[i] {
			j = f[j]
		}
		// If there is a match, increment j
		if b[j + 1] == b[i] {
			j++
		}
		// Set the failure function value for the current position
		f[i] = j
	}
}

func main() {
	// Create an input reader and output writer
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)

	// Read the length of the strings
	n, _ := strconv.Atoi(readLine(in))
	// Read the two strings
	s1 := readLine(in)
	str := readLine(in)
	cnt := 0

	// Concatenate the second string into the character array
	for i := 0; i < n; i++ {
		b[i+1] = str[i]
	}
	// Concatenate the first string into the character array
	for i := 0; i < n; i++ {
		b[i+1+n] = s1[i]
	}

	// Compute the failure function for the concatenated strings
	getFail(b[:], n+n)

	// Calculate the length of the longest prefix which is also a suffix
	len := min(f[n+n], min(n, n))
	// Output the result based on the calculated length
	fmt.Println(2*n - len)
	out.Flush() // Ensure all output is written
}

// Function to read a line of input from stdin
func readLine(in *bufio.Reader) string {
	buf := make([]byte, 0, 1024)

	for {
		line, isPrefix, err := in.ReadLine()
		if err!= nil {
			panic(err)
		}
		buf = append(buf, line...)
		if!isPrefix {
			break
		}
	}

	return strings.TrimSpace(string(buf))
}

// Function to return the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

