package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Set up input and output streams
	inputStream := os.Stdin
	outputStream := os.Stdout

	// Initialize InputReader for reading input and PrintWriter for output
	in := NewInputReader(inputStream)
	out := NewPrintWriter(outputStream)

	// Create an instance of Solution to solve the problem
	sol := NewSolution()
	sol.Solve(in, out)

	// Close the output stream
	out.Close()
}

type InputReader struct {
	reader *bufio.Reader
}

func NewInputReader(stream io.Reader) *InputReader {
	return &InputReader{
		reader: bufio.NewReader(stream),
	}
}

func (in *InputReader) Next() string {
	// Read a new line if the tokenizer is empty
	for in.tokenizer == nil || !in.tokenizer.Scan() {
		in.tokenizer = bufio.NewScanner(in.reader)
		in.tokenizer.Split(bufio.ScanWords)
	}
	return in.tokenizer.Text()
}

func (in *InputReader) NextInt() int {
	return int(in.NextInt64())
}

func (in *InputReader) NextInt64() int64 {
	return int64(in.NextInt64())
}

func (in *InputReader) ReadArray(n int) []int {
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i] = in.NextInt()
	}
	return a
}

type PrintWriter struct {
	writer *bufio.Writer
}

func NewPrintWriter(stream io.Writer) *PrintWriter {
	return &PrintWriter{
		writer: bufio.NewWriter(stream),
	}
}

func (out *PrintWriter) Print(a ...interface{}) {
	fmt.Fprint(out.writer, a...)
}

func (out *PrintWriter) Printf(format string, a ...interface{}) {
	fmt.Fprintf(out.writer, format, a...)
}

func (out *PrintWriter) Println(a ...interface{}) {
	fmt.Fprintln(out.writer, a...)
}

func (out *PrintWriter) Close() {
	out.writer.Flush()
}

type Solution struct {
}

func NewSolution() *Solution {
	return &Solution{}
}

func (sol *Solution) Solve(in *InputReader, out *PrintWriter) {
	// Read the number of logs and the value of k
	n := in.NextInt()
	k := in.NextInt()

	// Read the lengths of the logs into an array
	logsLength := in.ReadArray(n)

	// Initialize binary search bounds
	min := 1
	max := int(1e9) + 1000

	// Perform binary search to find the minimum possible length
	for min < max {
		mid := (min + max) / 2

		// Check if it's possible to cut the logs with the current mid length
		if sol.nei(mid, logsLength, k) {
			max = mid
		} else {
			min = mid + 1
		}
	}

	// Output the minimum length found
	out.Println(min)
}

func (sol *Solution) nei(mid int, logsLength []int, k int) bool {
	for _, log := range logsLength {
		k -= (log + mid - 1) / mid - 1
	}

	// Return true if we can make the cuts within the limit of k
	return k >= 0
}

// 