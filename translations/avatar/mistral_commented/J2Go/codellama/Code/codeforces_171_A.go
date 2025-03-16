// Importing necessary packages
import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Defining a struct for FastReader
type FastReader struct {
	br *bufio.Reader
	st *strings.Reader
}

// Constructor for FastReader
func NewFastReader() *FastReader {
	return &FastReader{
		br: bufio.NewReader(os.Stdin),
	}
}

// Method for reading next token
func (f *FastReader) next() string {
	for f.st == nil || !f.st.Scan() {
		var err error
		f.st, err = f.br.ReadString('\n')
		if err != nil {
			panic(err)
		}
	}
	return f.st.Text()
}

// Methods for reading specific types of input
func (f *FastReader) nextInt() int {
	return int(f.nextInt64())
}

func (f *FastReader) nextInt64() int64 {
	i, err := strconv.ParseInt(f.next(), 10, 64)
	if err != nil {
		panic(err)
	}
	return i
}

func (f *FastReader) nextFloat64() float64 {
	f64, err := strconv.ParseFloat(f.next(), 64)
	if err != nil {
		panic(err)
	}
	return f64
}

func (f *FastReader) nextString() string {
	return f.next()
}

// Main method
func main() {
	// Creating an instance of FastReader
	sc := NewFastReader()

	// Reading input for number of test cases
	n := sc.nextInt()

	// Reading input for number of operations
	m := sc.nextInt()

	// Calling reverse function for m and adding it to n
	t := reverse(m)
	fmt.Println(t + n)
}

// Function for reversing a number
func reverse(n int) int {
	// Base case for numbers less than 10
	if n < 10 {
		return n * 10
	}

	// Initializing variables
	t := n
	r := 0

	// Reversing the number
	for t > 0 {
		// Adding the digit to the reversed number
		r = (r * 10) + t%10

		// Moving to the next digit
		t = t / 10
	}

	// Returning the reversed number
	return r
}

// 