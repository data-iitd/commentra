
package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

// Main method to start the program
func main() {
	inputStream := os.Stdin // Input stream from standard input
	outputStream := os.Stdout // Output stream to standard output
	in := NewInputReader(inputStream) // Initialize InputReader
	out := NewPrintWriter(outputStream) // Initialize PrintWriter
	solver := NewTaskD() // Initialize TaskD solver
	solver.Solve(1, in, out) // Solve the problem and print the result
	out.Close() // Close the PrintWriter
}

// Static inner class to solve the problem
type TaskD struct{}

// Method to solve the problem and print the result
func (solver *TaskD) Solve(testNumber int, in *InputReader, out *PrintWriter) {
	// Read input
	n := in.NextInt() // Number of elements in array a
	m := in.NextInt() // Modulus value

	// Initialize data structures
	a := in.NextIntArray(n) // Read array a
	dp := make(map[int]int) // Hashmap to store intermediate results

	// Initialize variables
	ans := 0 // Answer variable
	base := 0 // Base value for hashmap key

	// Process each element in array a
	for i := 0; i < n; i++ {
		// Update base value
		base = (base - a[i]%m + m) % m

		// Update hashmap with current base and its count
		dp[base+a[i]%m]++

		// Update answer variable
		ans += dp[base]
	}

	// Print the answer
	out.Println(ans)
}

// Static inner class to read input
type InputReader struct {
	br *bufio.Reader
	st *strings.Reader
}

// Method to create a new InputReader
func NewInputReader(inputStream io.Reader) *InputReader {
	return &InputReader{
		br: bufio.NewReader(inputStream),
		st: strings.NewReader(""),
	}
}

// Method to read a string token
func (in *InputReader) NextString() string {
	for !in.st.Scan() {
		line, _, err := in.br.ReadLine()
		if err != nil {
			panic(err)
		}
		in.st = strings.NewReader(string(line))
	}
	return in.st.Text()
}

// Method to read an integer token
func (in *InputReader) NextInt() int {
	return int(in.NextInt64())
}

// Method to read an integer token
func (in *InputReader) NextInt64() int64 {
	return int64(in.NextInt64AsInt64())
}

// Method to read an integer token
func (in *InputReader) NextInt64AsInt64() int64 {
	str := in.NextString()
	val, err := strconv.ParseInt(str, 10, 64)
	if err != nil {
		panic(err)
	}
	return val
}

// Method to read an array of integers
func (in *InputReader) NextIntArray(n int) []int {
	res := make([]int, n)
	for i := 0; i < n; i++ {
		res[i] = in.NextInt()
	}
	return res
}

// Static inner class to print output
type PrintWriter struct {
	out io.Writer
}

// Method to create a new PrintWriter
func NewPrintWriter(outputStream io.Writer) *PrintWriter {
	return &PrintWriter{
		out: outputStream,
	}
}

// Method to print a string
func (out *PrintWriter) Println(str string) {
	fmt.Fprintln(out.out, str)
}

// Method to close the PrintWriter
func (out *PrintWriter) Close() {
	if closer, ok := out.out.(io.Closer); ok {
		closer.Close()
	}
}

