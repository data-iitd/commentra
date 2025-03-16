
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

// Initializing scanner and writer
var sc, wr = bufio.NewScanner(os.Stdin), bufio.NewWriter(os.Stdout)

// Function to read a single string
func scanString() string {
	sc.Scan()
	return sc.Text()
}

// Function to read a single rune
func scanRunes() []rune {
	return []rune(scanString())
}

// Function to read a single integer
func scanInt() int {
	a, _ := strconv.Atoi(scanString())
	return a
}

// Function to read a single integer64
func scanInt64() int64 {
	a, _ := strconv.ParseInt(scanString(), 10, 64)
	return a
}

// Function to read a single float64
func scanFloat64() float64 {
	a, _ := strconv.ParseFloat(scanString(), 64)
	return a
}

// Function to read multiple integers
func scanInts(n int) []int {
	res := make([]int, n)
	for i := 0; i < n; i++ {
		res[i] = scanInt()
	}
	return res
}

// Function to print debug information
func debug(a ...interface{}) { fmt.Fprintln(os.Stderr, a...) }

// Function to get absolute value of an integer
func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}

// Function to get minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// Function to get maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Main function
func main() {
	defer wr.Flush() // Flush the buffer after writing to it
	sc.Split(bufio.ScanWords) // Split the input into words
	sc.Buffer(make([]byte, 10000), 1001001) // Set buffer size

	// Reading input strings s and t
	s := scanRunes()
	t := scanRunes()

	// Initializing an empty slice to store answers
	ans := []string{}

	// Iterating through all possible substrings of s that have the same length as t
	for i := 0; i < len(s)-len(t)+1; i++ {
		// Initializing a slice to store the modified string s
		ss := make([]rune, len(s))
		copy(ss, s)

		// Checking if the current substring matches the pattern t
		f := true
		for j := 0; j < len(t); j++ {
			// If the current character of s does not match the current character of t or is not '?'
			if ss[i+j] != t[j] && ss[i+j] != '?' {
				// Setting flag to false and breaking the loop
				f = false
				break
			} else {
				// Replacing the current character of s with the corresponding character of t
				ss[i+j] = t[j]
			}
		}
		// If the current substring matches the pattern t
		if f {
			// Appending the modified string to the answer slice
			ans = append(ans, strings.Replace(string(ss), "?", "a", -1))
		}
	}
	// Sorting the answer slice in ascending order
	sort.Strings(ans)
	// Checking if the answer slice is empty
	if len(ans) == 0 {
		// Printing "UNRESTORABLE" if the answer slice is empty
		fmt.Fprintln(wr, "UNRESTORABLE")
	} else {
		// Printing the first element of the answer slice
		fmt.Fprintln(wr, ans[0])
	}
}

