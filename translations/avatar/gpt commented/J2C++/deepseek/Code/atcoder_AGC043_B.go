package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

// Method to calculate a specific value based on the input string and character
func cal(s string, c byte) int {
	n := len(s) // Get the length of the string
	m := n - 1  // Calculate the last index of the string
	ans := 0    // Initialize the answer variable

	// Iterate through each character in the string
	for i := 0; i < n; i++ {
		// Check if the current character matches 'c' and if the bitwise AND of m and i equals i
		if s[i] == c && (m&i) == i {
			ans ^= 1 // Toggle the answer using XOR operation
		}
	}
	return ans // Return the final calculated answer
}

// Main logic to solve the problem
func solve() {
	n := nextInt() // Read the integer input for the length of the string
	s := next()    // Read the string input
	var sb strings.Builder // Initialize a StringBuilder to build the new string

	// Build a new string based on the absolute differences between adjacent characters
	for i := 1; i < n; i++ {
		sb.WriteString(strconv.Itoa(int(s[i]) - int(s[i-1]))) // Append the absolute difference
	}

	// Special case when the length of the string is 2
	if n == 2 {
		fmt.Fprintln(out, sb.String()[0]) // Print the first character of the new string
		return // Exit the method
	}

	// Convert the StringBuilder to a string
	s = sb.String()

	// Check if the new string contains the character '1'
	if strings.Contains(s, "1") {
		fmt.Fprintln(out, cal(s, '1')) // Calculate and print the result for character '1'
	} else {
		fmt.Fprintln(out, cal(s, '2')*2) // Calculate and print the result for character '2', multiplied by 2
	}
}

// Static variables for output and input handling
var (
	out io.Writer = os.Stdout
	in  io.Reader = os.Stdin
)

// Custom scanner class for input handling
type MyScanner struct {
	sc *bufio.Scanner
}

// Constructor to initialize BufferedReader
func NewMyScanner() *MyScanner {
	sc := bufio.NewScanner(in)
	sc.Split(bufio.ScanWords)
	return &MyScanner{sc: sc}
}

// Method to read the next token from input
func (ms *MyScanner) next() string {
	ms.sc.Scan()
	return ms.sc.Text()
}

// Method to read the next integer from input
func (ms *MyScanner) nextInt() int {
	n, _ := strconv.Atoi(ms.next())
	return n
}

// Method to read the next long from input
func (ms *MyScanner) nextLong() int64 {
	n, _ := strconv.ParseInt(ms.next(), 10, 64)
	return n
}

// Method to read the next double from input
func (ms *MyScanner) nextDouble() float64 {
	n, _ := strconv.ParseFloat(ms.next(), 64)
	return n
}

func main() {
	sc := NewMyScanner()
	defer out.Close()
	solve()
}
