package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

// Initialize scanner and writer for input and output
var sc, wr = bufio.NewScanner(os.Stdin), bufio.NewWriter(os.Stdout)

// Function to scan a single string from input
func scanString() string {
	sc.Scan()
	return sc.Text()
}

// Function to scan a slice of runes from input
func scanRunes() []rune {
	return []rune(scanString())
}

// Function to scan a single integer from input
func scanInt() int {
	a, _ := strconv.Atoi(scanString())
	return a
}

// Function to scan a single int64 from input
func scanInt64() int64 {
	a, _ := strconv.ParseInt(scanString(), 10, 64)
	return a
}

// Function to scan a single float64 from input
func scanFloat64() float64 {
	a, _ := strconv.ParseFloat(scanString(), 64)
	return a
}

// Function to scan n integers from input and return them as a slice
func scanInts(n int) []int {
	res := make([]int, n)
	for i := 0; i < n; i++ {
		res[i] = scanInt()
	}
	return res
}

// Debug function to print messages to stderr
func debug(a ...interface{}) {
	fmt.Fprintln(os.Stderr, a...)
}

// Function to return the absolute value of an integer
func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}

// Function to return the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// Function to return the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Main function where the program execution begins
func main() {
	// Ensure the buffered writer flushes its content before exiting
	defer wr.Flush()

	// Set the scanner to split input by whitespace and configure buffer size
	sc.Split(bufio.ScanWords)
	sc.Buffer(make([]byte, 10000), 1001001)

	// Read the first string of runes (s)
	s := scanRunes()
	// Read the second string of runes (t)
	t := scanRunes()

	// Initialize a slice to hold possible answers
	ans := []string{}
	
	// Iterate through the first string to find occurrences of the second string
	for i := 0; i < len(s)-len(t)+1; i++ {
		f := true // Flag to check if the current position is valid
		ss := make([]rune, len(s)) // Create a copy of the original string
		copy(ss, s) // Copy the original string into ss

		// Check if the substring of s can match t
		for j := 0; j < len(t); j++ {
			// If characters do not match and are not '?', set flag to false
			if s[i+j] != t[j] && s[i+j] != '?' {
				f = false
				break
			} else {
				// Replace '?' with the corresponding character from t
				ss[i+j] = t[j]
			}
		}
		// If the substring matched, replace remaining '?' with 'a' and store the result
		if f {
			ans = append(ans, strings.Replace(string(ss), "?", "a", -1))
		}
	}

	// Sort the possible answers
	sort.Strings(ans)

	// Output the result: either the first valid answer or "UNRESTORABLE"
	if len(ans) == 0 {
		fmt.Fprintln(wr, "UNRESTORABLE")
	} else {
		fmt.Fprintln(wr, ans[0])
	}
}
