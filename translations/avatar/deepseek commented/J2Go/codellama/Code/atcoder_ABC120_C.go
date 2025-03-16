package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Set up the standard input and output streams
	inputStream := os.Stdin
	outputStream := os.Stdout
	// Create an InputReader to read input from the standard input stream
	in := &InputReader{
		reader: bufio.NewReader(inputStream),
	}
	// Create a PrintWriter to write output to the standard output stream
	out := bufio.NewWriter(outputStream)
	// Create an instance of TaskB and call its solve method
	solver := &TaskB{}
	solver.solve(1, in, out)
	// Close the PrintWriter to flush the output and close the stream
	out.Flush()
}

// TaskB class contains the main logic of the program
type TaskB struct{}

// The solve method implements the main logic
func (solver *TaskB) solve(testNumber int, in *InputReader, out *bufio.Writer) {
	// Read the input string
	x := in.next()
	// Initialize a stack to keep track of characters
	s := make([]rune, 0)
	// Initialize a counter to count balanced pairs
	c := 0
	// Iterate through each character in the input string
	for i := 0; i < len(x); i++ {
		// Push the current character onto the stack
		s = append(s, rune(x[i]))
		// While the stack has more than one element, check for balanced pairs
		for len(s) > 1 {
			// Pop the top two elements from the stack
			p := s[len(s)-1]
			s = s[:len(s)-1]
			q := s[len(s)-1]
			s = s[:len(s)-1]
			// Check if they form a balanced pair
			if (p == '1' && q == '0') || (p == '0' && q == '1') {
				// Increment the counter if a balanced pair is found
				c++
				continue
			} else {
				// If not a balanced pair, push the popped elements back onto the stack
				s = append(s, q)
				s = append(s, p)
				break
			}
		}
	}
	// Output the result, which is twice the counter value
	fmt.Fprintln(out, c*2)
}

// Helper class to read input from the standard input stream
type InputReader struct {
	reader *bufio.Reader
}

// Method to read the next token from the input stream
func (in *InputReader) next() string {
	var token string
	for token == "" {
		var err error
		token, err = in.reader.ReadString('\n')
		if err != nil {
			panic(err)
		}
		token = strings.Trim(token, "\n")
	}
	return token
}

// Method to read the next integer from the input stream
func (in *InputReader) nextInt() int {
	var token string
	for token == "" {
		var err error
		token, err = in.reader.ReadString('\n')
		if err != nil {
			panic(err)
		}
		token = strings.Trim(token, "\n")
	}
	i, err := strconv.Atoi(token)
	if err != nil {
		panic(err)
	}
	return i
}

// Method to read the next integer array from the input stream
func (in *InputReader) nextIntArray() []int {
	var token string
	for token == "" {
		var err error
		token, err = in.reader.ReadString('\n')
		if err != nil {
			panic(err)
		}
		token = strings.Trim(token, "\n")
	}
	arr := strings.Split(token, " ")
	var res []int
	for _, s := range arr {
		i, err := strconv.Atoi(s)
		if err != nil {
			panic(err)
		}
		res = append(res, i)
	}
	return res
}

// Method to read the next integer matrix from the input stream
func (in *InputReader) nextIntMatrix() [][]int {
	var token string
	for token == "" {
		var err error
		token, err = in.reader.ReadString('\n')
		if err != nil {
			panic(err)
		}
		token = strings.Trim(token, "\n")
	}
	arr := strings.Split(token, "\n")
	var res [][]int
	for _, s := range arr {
		arr := strings.Split(s, " ")
		var tmp []int
		for _, s := range arr {
			i, err := strconv.Atoi(s)
			if err != nil {
				panic(err)
			}
			tmp = append(tmp, i)
		}
		res = append(res, tmp)
	}
	return res
}

// Method to read the next string from the input stream
func (in *InputReader) nextString() string {
	var token string
	for token == "" {
		var err error
		token, err = in.reader.ReadString('\n')
		if err != nil {
			panic(err)
		}
		token = strings.Trim(token, "\n")
	}
	return token
}

// Method to read the next string array from the input stream
func (in *InputReader) nextStringArray() []string {
	var token string
	for token == "" {
		var err error
		token, err = in.reader.ReadString('\n')
		if err != nil {
			panic(err)
		}
		token = strings.Trim(token, "\n")
	}
	arr := strings.Split(token, " ")
	var res []string
	for _, s := range arr {
		res = append(res, s)
	}
	return res
}

// Method to read the next string matrix from the input stream
func (in *InputReader) nextStringMatrix() [][]string {
	var token string
	for token == "" {
		var err error
		token, err = in.reader.ReadString('\n')
		if err != nil {
			panic(err)
		}
		token = strings.Trim(token, "\n")
	}
	arr := strings.Split(token, "\n")
	var res [][]string
	for _, s := range arr {
		arr := strings.Split(s, " ")
		var tmp []string
		for _, s := range arr {
			tmp = append(tmp, s)
		}
		res = append(res, tmp)
	}
	return res
}

// Method to read the next line from the input stream
func (in *InputReader) nextLine() string {
	var token string
	for token == "" {
		var err error
		token, err = in.reader.ReadString('\n')
		if err != nil {
			panic(err)
		}
		token = strings.Trim(token, "\n")
	}
	return token
}

// Method to read the next line array from the input stream
func (in *InputReader) nextLineArray() []string {
	var token string
	for token == "" {
		var err error
		token, err = in.reader.ReadString('\n')
		if err != nil {
			panic(err)
		}
		token = strings.Trim(token, "\n")
	}
	arr := strings.Split(token, "\n")
	var res []string
	for _, s := range arr {
		res = append(res, s)
	}
	return res
}

// Method to read the next line matrix from the input stream
func (in *InputReader) nextLineMatrix() [][]string {
	var token string
	for token == "" {
		var err error
		token, err = in.reader.ReadString('\n')
		if err != nil {
			panic(err)
		}
		token = strings.Trim(token, "\n")
	}
	arr := strings.Split(token, "\n")
	var res [][]string
	for _, s := range arr {
		arr := strings.Split(s, " ")
		var tmp []string
		for _, s := range arr {
			tmp = append(tmp, s)
		}
		res = append(res, tmp)
	}
	return res
}

// Method to read the next float from the input stream
func (in *InputReader) nextFloat() float64 {
	var token string
	for token == "" {
		var err error
		token, err = in.reader.ReadString('\n')
		if err != nil {
			panic(err)
		}
		token = strings.Trim(token, "\n")
	}
	f, err := strconv.ParseFloat(token, 64)
	if err != nil {
		panic(err)
	}
	return f
}

// Method to read the next float array from the input stream
func (in *InputReader) nextFloatArray() []float64 {
	var token string
	for token == "" {
		var err error
		token, err = in.reader.ReadString('\n')
		if err != nil {
			panic(err)
		}
		token = strings.Trim(token, "\n")
	}
	arr := strings.Split(token, " ")
	var res []float64
	for _, s := range arr {
		f, err := strconv.ParseFloat(s, 64)
		if err != nil {
			panic(err)
		}
		res = append(res, f)
	}
	return res
}

// Method to read the next float matrix from the input stream
func (in *InputReader) nextFloatMatrix() [][]float64 {
	var token string
	for token == "" {
		var err error
		token, err = in.reader.ReadString('\n')
		if err != nil {
			panic(err)
		}
		token = strings.Trim(token, "\n")
	}
	arr := strings.Split(token, "\n")
	var res [][]float64
	for _, s := range arr {
		arr := strings.Split(s, " ")
		var tmp []float64
		for _, s := range arr {
			f, err := strconv.ParseFloat(s, 64)
			if err != nil {
				panic(err)
			}
			tmp = append(tmp, f)
		}
		res = append(res, tmp)
	}
	return res
}

// Method to read the next boolean from the input stream
func (in *InputReader) nextBool() bool {
	var token string
	for token == "" {
		var err error
		token, err = in.reader.ReadString('\n')
		if err != nil {
			panic(err)
		}
		token = strings.Trim(token, "\n")
	}
	b, err := strconv.ParseBool(token)
	if err != nil {
		panic(err)
	}
	return b
}

// Method to read the next boolean array from the input stream
func (in *InputReader) nextBoolArray() []bool {
	var token string
	for token == "" {
		var err error
		token, err = in.reader.ReadString('\n')
		if err != nil {
			panic(err)
		}
		token = strings.Trim(token, "\n")
	}
	arr := strings.Split(token, " ")
	var res []bool
	for _, s := range arr {
		b, err := strconv.ParseBool(s)
		if err != nil {
			panic(err)
		}
		res = append(res, b)
	}
	return res
}

// Method to read the next boolean matrix from the input stream
func (in *InputReader) nextBoolMatrix() [][]bool {
	var token string
	for token == "" {
		var err error
		token, err = in.reader.ReadString('\n')
		if err != nil {
			panic(err)
		}
		token = strings.Trim(token, "\n")
	}
	arr := strings.Split(token, "\n")
	var res [][]bool
	for _, s := range arr {
		arr := strings.Split(s, " ")
		var tmp []bool
		for _, s := range arr {
			b, err := strconv.ParseBool(s)
			if err != nil {
				panic(err)
			}
			tmp = append(tmp, b)
		}
		res = append(res, tmp)
	}
	return res
}

// Method to read the next rune from the input stream
func (in *InputReader) nextRune() rune {
	var token string
	for token == "" {
		var err error
		token, err = in.reader.ReadString('\n')
		if err != nil {
			panic(err)
		}
		token = strings.Trim(token, "\n")
	}
	r, err := strconv.Unquote(fmt.Sprintf("\"%s\"", token))
	if err != nil {
		panic(err)
	}
	return r
}

// Method to read the next rune array from the input stream
func (in *InputReader) nextRuneArray() []rune {
	var token string
	for token == "" {
		var err error
		token, err = in.reader.ReadString('\n')
		if err != nil {
			panic(err)
		}
		token = strings.Trim(token, "\n")
	}
	arr := strings.Split(token, " ")
	var res []rune
	for _, s := range arr {
		r, err := strconv.Unquote(fmt.Sprintf("\"%s\"", s))
		if err != nil {
			panic(err)
		}
		res = append(res, r)
	}
	return res
}

// Method to read the next rune matrix from the input stream
func (in *InputReader) nextRuneMatrix() [][]rune {
	var token string
	for token == "" {
		var err error
		token, err = in.reader.ReadString('\n')
		if err != nil {
			panic(err)
		}
		token = strings.Trim(token, "\n")
	}
	arr := strings.Split(token, "\n")
	var res [][]rune
	for _, s := range arr {
		arr := strings.Sp