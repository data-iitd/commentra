package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	// Initialize input and output streams
	inputStream := os.Stdin
	outputStream := os.Stdout

	// Create InputReader and PrintWriter objects
	in := NewInputReader(inputStream)
	out := NewPrintWriter(outputStream)

	// Create Solution object and call its solve method
	sol := NewSolution()
	sol.Solve(in, out)

	// Close the output stream
	out.Close()
}

// Private nested class for solving the problem
type Solution struct{}

// Method to solve the problem
func (sol *Solution) Solve(in *InputReader, out *PrintWriter) {
	// Read input: number of elements n and the number of summands k
	n := in.Ni()
	k := in.Ni()

	// Read input array a of size n
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i] = in.Ni() // Read next element of array a
	}

	// Sort the array a in parallel using sort.Ints()
	sort.Ints(a)

	// Calculate the answer: sum of first k elements of sorted array a
	ans := 0
	for i := 0; i < k; i++ {
		ans += a[i]
	}

	// Write the answer to the output stream
	out.Println(ans)
}

// Nested static class for reading input
type InputReader struct {
	reader *bufio.Reader
	tokenizer *strings.Tokenizer
}

// Constructor to initialize InputReader with input stream
func NewInputReader(stream io.Reader) *InputReader {
	return &InputReader{
		reader: bufio.NewReader(stream),
		tokenizer: nil,
	}
}

// Method to read a string token
func (in *InputReader) N() string {
	for in.tokenizer == nil || !in.tokenizer.Scan() {
		in.tokenizer = strings.NewTokenizer(in.reader.ReadString('\n'))
	}
	return in.tokenizer.Token().String()
}

// Method to read an integer
func (in *InputReader) Ni() int {
	return strconv.Atoi(in.N())
}

// Nested static class for writing output
type PrintWriter struct {
	writer *bufio.Writer
}

// Constructor to initialize PrintWriter with output stream
func NewPrintWriter(stream io.Writer) *PrintWriter {
	return &PrintWriter{
		writer: bufio.NewWriter(stream),
	}
}

// Method to write a string to the output stream
func (out *PrintWriter) Println(s string) {
	fmt.Fprintln(out.writer, s)
}

// Method to close the output stream
func (out *PrintWriter) Close() {
	out.writer.Flush()
}

