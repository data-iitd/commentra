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
	// Initialize input and output streams
	inputStream := os.Stdin
	outputStream := os.Stdout

	// Initialize InputReader and PrintWriter
	in := NewInputReader(inputStream)
	out := bufio.NewWriter(outputStream)
	defer out.Flush()

	// Initialize TaskD solver
	solver := TaskD{}

	// Solve the problem and print the result
	solver.solve(in, out)
}

// TaskD struct to solve the problem
type TaskD struct{}

// solve method to solve the problem
func (td TaskD) solve(in *InputReader, out io.Writer) {
	// Read input
	n := in.nextInt() // Number of elements in array a
	m := in.nextInt() // Modulus value

	// Initialize data structures
	a := in.nextIntArray(n) // Read array a
	dp := make(map[int]int)  // Hashmap to store intermediate results

	// Initialize variables
	var ans int64 = 0 // Answer variable
	base := 0        // Base value for hashmap key

	// Process each element in array a
	for i := 0; i < n; i++ {
		// Update base value
		base = (base - a[i]%m + m) % m

		// Update hashmap with current base and its count
		dp[(base+a[i]%m)]++

		// Update answer variable
		ans += int64(dp[base])
	}

	// Print the answer
	fmt.Fprintln(out, ans)
}

// InputReader struct to read input
type InputReader struct {
	sc *bufio.Scanner
}

// NewInputReader initializes a new InputReader
func NewInputReader(inputStream io.Reader) *InputReader {
	sc := bufio.NewScanner(inputStream)
	sc.Split(bufio.ScanWords)
	return &InputReader{sc}
}

// nextString reads the next word from the input and returns it as a string
func (ir *InputReader) nextString() string {
	sc := ir.sc
	sc.Scan()
	return sc.Text()
}

// nextInt reads the next word from the input, converts it to an integer, and returns it
func (ir *InputReader) nextInt() int {
	sc := ir.sc
	sc.Scan()
	n, err := strconv.Atoi(sc.Text())
	if err != nil {
		panic(err)
	}
	return n
}

// nextIntArray reads the next n integers from the input and returns them as an array
func (ir *InputReader) nextIntArray(n int) []int {
	res := make([]int, n)
	for i := 0; i < n; i++ {
		res[i] = ir.nextInt()
	}
	return res
}
