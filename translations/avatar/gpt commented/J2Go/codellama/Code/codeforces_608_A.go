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
	in := NewFastScanner()
	// Create a Scanner object for standard input
	sc := bufio.NewScanner(os.Stdin)
	// Create a PrintWriter object for output
	o := bufio.NewWriter(os.Stdout)

	// Read the number of pairs (n) and the minimum score (s)
	n, _ := strconv.Atoi(in.next())
	s, _ := strconv.Atoi(in.next())

	// Initialize a variable to keep track of the maximum sum of pairs
	max := 0

	// Loop through each pair of integers
	for n > 0 {
		// Read the two integers f and t
		f, _ := strconv.Atoi(in.next())
		t, _ := strconv.Atoi(in.next())
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
	br *bufio.Reader
	st *strings.Reader
}

// Method to read the next token
func (f *FastScanner) next() string {
	// Read new line if no more tokens are available
	for !f.st.Scan() {
		f.st = strings.NewReader(f.br.Text())
	}
	return f.st.Text()
}

// Method to read the next line
func (f *FastScanner) nextLine() string {
	str := ""
	for {
		str += f.next()
		if str[len(str)-1] == '\n' {
			return str[:len(str)-1]
		}
	}
}

// Methods to read different data types
func (f *FastScanner) nextByte() byte {
	i, _ := strconv.Atoi(f.next())
	return byte(i)
}

func (f *FastScanner) nextShort() int16 {
	i, _ := strconv.Atoi(f.next())
	return int16(i)
}

func (f *FastScanner) nextInt() int {
	i, _ := strconv.Atoi(f.next())
	return i
}

func (f *FastScanner) nextLong() int64 {
	i, _ := strconv.ParseInt(f.next(), 10, 64)
	return i
}

func (f *FastScanner) nextDouble() float64 {
	i, _ := strconv.ParseFloat(f.next(), 64)
	return i
}

// NewFastScanner creates a new FastScanner object
func NewFastScanner() *FastScanner {
	return &FastScanner{
		br: bufio.NewReader(os.Stdin),
		st: strings.NewReader(""),
	}
}

