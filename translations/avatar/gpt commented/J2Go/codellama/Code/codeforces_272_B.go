package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

// FastReader class for efficient input reading
type FastReader struct {
	br   *bufio.Reader
	st   *strings.Reader
	line string
}

// Constructor to initialize BufferedReader
func NewFastReader() *FastReader {
	return &FastReader{br: bufio.NewReader(os.Stdin)}
}

// Method to read the next token as a String
func (f *FastReader) next() string {
	// Read a new line if the current tokenizer is exhausted
	if f.st == nil || !f.st.Scan() {
		f.st = nil
		f.line, _ = f.br.ReadString('\n')
		f.st = strings.NewReader(f.line)
	}
	return f.st.Text()
}

// Method to read the next token as an integer
func (f *FastReader) nextInt() int {
	return int(f.nextInt64())
}

// Method to read the next token as a long
func (f *FastReader) nextInt64() int64 {
	return int64(f.nextInt64())
}

// Method to read the next token as a double
func (f *FastReader) nextDouble() float64 {
	return float64(f.nextDouble())
}

// Method to read the next line as a String
func (f *FastReader) nextLine() string {
	return f.line
}

// Method to count the number of set bits (1s) in the binary representation of x
func rec(x int64) int {
	answer := 0
	// Iterate through each bit position from 31 to 0
	for k := 31; k >= 0; k-- {
		// Check if the k-th bit is set
		if (x & (1 << k)) != 0 {
			answer++
		}
	}
	return answer
}

func main() {
	// Initialize FastReader for input and PrintWriter for output
	sc := NewFastReader()
	out := bufio.NewWriter(os.Stdout)

	// Read the number of integers to process
	n := sc.nextInt()

	// Array to count occurrences of integers based on their bit count
	a := make([]int, 33)

	// Process each integer and count how many have the same number of set bits
	for i := 0; i < n; i++ {
		a[rec(int64(sc.nextInt64()))]++
	}

	// Variable to accumulate the final answer
	answer := 0.0

	// Calculate the contribution to the answer from each bit count
	for i := 0; i < len(a); i++ {
		summ := (1 + float64(a[i]) - 1) / 2.0 * float64(a[i]-1)
		answer += summ
	}

	// Print the final answer as a long integer
	fmt.Fprintln(out, int64(answer))
	out.Flush()
}

// END-OF-CODE
