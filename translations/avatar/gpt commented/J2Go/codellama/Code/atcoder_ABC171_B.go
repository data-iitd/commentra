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
	// Set up input and output streams
	inputStream := os.Stdin
	outputStream := os.Stdout

	// Create an InputReader to read input from the input stream
	in := &InputReader{
		reader: bufio.NewReader(inputStream),
	}

	// Create a PrintWriter to write output to the output stream
	out := &PrintWriter{
		writer: bufio.NewWriter(outputStream),
	}

	// Create an instance of the Solution class to solve the problem
	sol := &Solution{}

	// Call the solve method to process the input and produce output
	sol.solve(in, out)

	// Close the PrintWriter to flush the output
	out.close()
}

type InputReader struct {
	reader *bufio.Reader
}

func (in *InputReader) n() string {
	// Read a new line if the tokenizer is null or has no more tokens
	for in.reader == nil || !in.reader.Scan() {
		in.reader = bufio.NewReader(os.Stdin)
	}
	return in.reader.Text()
}

func (in *InputReader) ni() int {
	return int(in.n())
}

type PrintWriter struct {
	writer *bufio.Writer
}

func (out *PrintWriter) println(a ...interface{}) {
	fmt.Fprintln(out.writer, a...)
}

func (out *PrintWriter) close() {
	out.writer.Flush()
}

type Solution struct{}

func (sol *Solution) solve(in *InputReader, out *PrintWriter) {
	// Read the number of elements (n) and the number of smallest elements to sum (k)
	n := in.ni()
	k := in.ni()

	// Initialize an array to hold the input numbers
	a := make([]int, n)

	// Read n integers from input and store them in the array
	for i := 0; i < n; i++ {
		a[i] = in.ni()
	}

	// Sort the array in parallel to arrange numbers in ascending order
	sort.Ints(a)

	// Initialize a variable to hold the sum of the smallest k elements
	ans := 0

	// Sum the first k elements of the sorted array
	for i := 0; i < k; i++ {
		ans += a[i]
	}

	// Output the result (sum of the smallest k elements)
	out.println(ans)
}

