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

	// Create an InputReader to read input data
	in := &InputReader{
		br: bufio.NewReader(inputStream),
		st: nil,
	}

	// Create a PrintWriter to output results
	out := bufio.NewWriter(outputStream)

	// Create an instance of TaskD to solve the problem
	solver := &TaskD{}

	// Solve the problem for the first test case
	solver.solve(1, in, out)

	// Close the output stream
	out.Flush()
}

type TaskD struct{}

func (solver *TaskD) solve(testNumber int, in *InputReader, out *bufio.Writer) {
	// Read the number of elements and the modulus value
	n := in.nextInt()
	m := in.nextInt()

	// Read the array of integers
	a := in.nextIntArray(n)

	// Initialize a HashMap to store counts of remainders
	dp := make(map[int]int)
	ans := 0 // Variable to store the final answer
	base := 0 // Variable to track the base remainder

	// Iterate through the array to calculate the answer
	for i := 0; i < n; i++ {
		// Update the base remainder
		base = (base - a[i]%m + m) % m

		// Merge the current remainder into the HashMap
		dp[(base+a[i])%m]++

		// Add the count of occurrences of the current base remainder to the answer
		ans += dp[base]
	}

	// Output the final answer
	fmt.Fprintln(out, ans)
}

type InputReader struct {
	br *bufio.Reader
	st *strings.Reader
}

func (in *InputReader) nextString() string {
	for !in.st.Scan() {
		line, isPrefix, err := in.br.ReadLine()
		if err != nil {
			panic(err)
		}
		if isPrefix {
			panic("Buffer overflow")
		}
		in.st = strings.NewReader(string(line))
	}
	return in.st.Text()
}

func (in *InputReader) nextInt() int {
	return int(in.nextInt64())
}

func (in *InputReader) nextInt64() int64 {
	return int64(in.nextInt64AsInt64())
}

func (in *InputReader) nextInt64AsInt64() int64 {
	s := in.nextString()
	x, err := strconv.ParseInt(s, 10, 64)
	if err != nil {
		panic(err)
	}
	return x
}

func (in *InputReader) nextIntArray(n int) []int {
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i] = in.nextInt()
	}
	return a
}

// 