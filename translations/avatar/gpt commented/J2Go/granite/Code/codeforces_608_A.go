
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Initialize FastScanner for efficient input reading
	in := NewFastScanner(os.Stdin)
	// Create a Scanner object for standard input
	sc := bufio.NewScanner(os.Stdin)
	// Create a PrintWriter object for output
	o := bufio.NewWriter(os.Stdout)

	// Read the number of pairs (n) and the minimum score (s)
	n, _ := strconv.Atoi(in.nextLine())
	s, _ := strconv.Atoi(in.nextLine())

	// Initialize a variable to keep track of the maximum sum of pairs
	max := 0

	// Loop through each pair of integers
	for n > 0 {
		// Read the two integers f and t
		f, _ := strconv.Atoi(in.nextLine())
		t, _ := strconv.Atoi(in.nextLine())
		// Update max if the sum of f and t is greater than the current max
		if max < f+t {
			max = f + t
		}
		n--
	}

	// Print the maximum value between max and s
	fmt.Fprintln(o, max)
	// Close the PrintWriter
	o.Flush()
}

// FastScanner class for efficient input handling
type FastScanner struct {
	reader *bufio.Reader
}

// NewFastScanner creates a new FastScanner
func NewFastScanner(r *os.File) *FastScanner {
	return &FastScanner{
		reader: bufio.NewReader(r),
	}
}

// Read the next token
func (f *FastScanner) next() string {
	token, _ := f.reader.ReadString('\n')
	return strings.TrimSpace(token)
}

// Read the next line
func (f *FastScanner) nextLine() string {
	line, _ := f.reader.ReadString('\n')
	return line
}

// Methods to read different data types
func (f *FastScanner) nextByte() byte {
	b, _ := strconv.ParseInt(f.next(), 10, 8)
	return byte(b)
}

func (f *FastScanner) nextShort() int16 {
	b, _ := strconv.ParseInt(f.next(), 10, 16)
	return int16(b)
}

func (f *FastScanner) nextInt() int {
	b, _ := strconv.ParseInt(f.next(), 10, 32)
	return int(b)
}

func (f *FastScanner) nextLong() int64 {
	b, _ := strconv.ParseInt(f.next(), 10, 64)
	return b
}

func (f *FastScanner) nextDouble() float64 {
	b, _ := strconv.ParseFloat(f.next(), 64)
	return b
}

// END-OF-CODE