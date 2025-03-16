package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Set up input and output streams
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)

	// Create an InputReader to read input from the input stream
	in := InputReader{reader}

	// Create a PrintWriter to write output to the output stream
	out := PrintWriter{writer}

	// Instantiate the Task class to solve the problem
	solver := Task{}

	// Call the solve method to process the input and produce output
	solver.solve(in, out)

	// Close the PrintWriter to flush and release resources
	out.close()
}

type InputReader struct {
	reader *bufio.Reader
}

func (self *InputReader) next() string {
	// Read a new line if the tokenizer is empty
	for self.tokenizer == nil ||!self.tokenizer.HasMoreTokens() {
		line, err := self.reader.ReadString('\n')
		if err!= nil {
			panic(err)
		}
		self.tokenizer = *new(strings.Tokenizer)
		self.tokenizer.Init(strings.NewReader(line))
	}
	return self.tokenizer.NextToken()
}

func (self *InputReader) nextInt() int {
	i, err := strconv.Atoi(self.next())
	if err!= nil {
		panic(err)
	}
	return i
}

func (self *InputReader) nextLong() int64 {
	i, err := strconv.ParseInt(self.next(), 10, 64)
	if err!= nil {
		panic(err)
	}
	return i
}

func (self *InputReader) nextDouble() float64 {
	i, err := strconv.ParseFloat(self.next(), 64)
	if err!= nil {
		panic(err)
	}
	return i
}

func (self *InputReader) nextLine() string {
	str, err := self.reader.ReadString('\n')
	if err!= nil {
		panic(err)
	}
	return str
}

type PrintWriter struct {
	writer *bufio.Writer
}

func (self *PrintWriter) println(a...interface{}) {
	fmt.Fprintln(self.writer, a...)
}

func (self *PrintWriter) printf(format string, a...interface{}) {
	fmt.Fprintf(self.writer, format, a...)
}

func (self *PrintWriter) close() {
	self.writer.Flush()
}

type Task struct {
}

func (self *Task) solve(in InputReader, out PrintWriter) {
	// Read the number of elements
	n := in.nextInt()

	// Initialize an array to count occurrences of each index (up to 1000)
	array := make([]int, 1001)

	// Read n integers and count their occurrences
	for i := 0; i < n; i++ {
		index := in.nextInt()
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
			out.println("YES")
		} else {
			out.println("NO")
		}
	} else {
		// For odd n, check if the maximum count is less than or equal to n/2 + 1
		if countMax <= n/2+1 {
			out.println("YES")
		} else {
			out.println("NO")
		}
	}
}

