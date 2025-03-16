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

	// Create an InputReader to read input from the input stream
	in := NewInputReader(inputStream)

	// Create a PrintWriter to write output to the output stream
	out := bufio.NewWriter(outputStream)

	// Instantiate the Task class to solve the problem
	solver := NewTask()

	// Call the solve method to process the input and produce output
	solver.Solve(in, out)

	// Close the PrintWriter to flush and release resources
	out.Flush()
}

type Task struct{}

func NewTask() *Task {
	return &Task{}
}

func (this *Task) Solve(in *InputReader, out *bufio.Writer) {
	// Read the number of elements
	n := in.NextInt()

	// Initialize an array to count occurrences of each index (up to 1000)
	array := make([]int, 1001)

	// Read n integers and count their occurrences
	for i := 0; i < n; i++ {
		index := in.NextInt()
		array[index]++
	}

	// Determine the maximum count of any index
	countMax := -1
	for i := 1; i < len(array); i++ {
		if countMax < array[i] {
			countMax = array[i]
		}
	}

	// Check if the maximum count is within allowed limits based on n being even or odd
	if n%2 == 0 {
		// For even n, check if the maximum count is less than or equal to n/2
		if countMax <= n/2 {
			fmt.Fprintln(out, "YES")
		} else {
			fmt.Fprintln(out, "NO")
		}
	} else {
		// For odd n, check if the maximum count is less than or equal to n/2 + 1
		if countMax <= n/2+1 {
			fmt.Fprintln(out, "YES")
		} else {
			fmt.Fprintln(out, "NO")
		}
	}
}

type InputReader struct {
	reader *bufio.Reader
	tokenizer *strings.Tokenizer
}

func NewInputReader(stream io.Reader) *InputReader {
	return &InputReader{
		reader: bufio.NewReader(stream),
	}
}

func (this *InputReader) Next() string {
	// Read a new line if the tokenizer is empty
	if this.tokenizer == nil || !this.tokenizer.Scan() {
		var err error
		this.tokenizer, err = this.reader.ReadString('\n')
		if err != nil {
			panic(err)
		}
	}
	return this.tokenizer.Token()
}

func (this *InputReader) NextInt() int {
	return strconv.Atoi(this.Next())
}

func (this *InputReader) NextLong() int64 {
	return strconv.ParseInt(this.Next(), 10, 64)
}

func (this *InputReader) NextDouble() float64 {
	return strconv.ParseFloat(this.Next(), 64)
}

func (this *InputReader) NextLine() string {
	str := ""
	var err error
	str, err = this.reader.ReadString('\n')
	if err != nil {
		panic(err)
	}
	return str
}

