
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Declaring global variables
var (
	g           [][]int
	maxMatching int
)

// Function to find the maximum number of edges that can be matched in a bipartite graph
func maxMatching(v, p int) int {
	a := 0
	o := 0

	// Iterating through all the neighbors of 'v'
	for _, w := range g[v] {
		if w == p {
			continue
		}

		// Recursively calling the function for the neighbor 'w' and updating the values of 'a' and 'o'
		r := maxMatching(w, v)
		a += r / 2
		o += r % 2
	}

	// Returning the result based on the parity of 'o'
	return 2*a + min(1, o)
}

func main() {
	// Creating an instance of MyScanner class for reading input
	sc := NewMyScanner()
	out := bufio.NewWriter(os.Stdout) // Creating an instance of bufio.Writer for output

	// Reading the number of vertices in the graph
	n, _ := strconv.Atoi(sc.next())

	// Initializing the graph as an array of arrays
	g = make([][]int, n)
	for i := range g {
		g[i] = make([]int, 0)
	}

	// Reading the edges and adding them to the graph
	for i := 0; i < n-1; i++ {
		a, _ := strconv.Atoi(sc.next())
		b, _ := strconv.Atoi(sc.next())
		g[a-1] = append(g[a-1], b-1)
		g[b-1] = append(g[b-1], a-1)
	}

	// Finding the maximum number of edges that can be matched in the graph
	maxMatching = maxMatching(0, -1) / 2

	// Printing the result based on whether all vertices have even degree or not
	if 2*maxMatching == n {
		fmt.Fprintln(out, "Second")
	} else {
		fmt.Fprintln(out, "First")
	}

	// Closing the output stream
	out.Flush()
}

// Function to return the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// MyScanner class for reading input
type MyScanner struct {
	s   *bufio.Scanner
	buf *bytes.Buffer
}

// Constructor for MyScanner class
func NewMyScanner() *MyScanner {
	return &MyScanner{
		s:   bufio.NewScanner(os.Stdin),
		buf: bytes.NewBuffer([]byte{}),
	}
}

// Function to read the next token from the input stream
func (this *MyScanner) next() string {
	if!this.s.Scan() {
		panic("Scan failed")
	}
	this.buf.WriteString(this.s.Text())
	return this.buf.String()
}

// Overloaded functions for reading different data types
func (this *MyScanner) nextInt() int {
	i, _ := strconv.Atoi(this.next())
	return i
}

func (this *MyScanner) nextLong() int64 {
	i, _ := strconv.ParseInt(this.next(), 10, 64)
	return i
}

func (this *MyScanner) nextDouble() float64 {
	i, _ := strconv.ParseFloat(this.next(), 64)
	return i
}

func (this *MyScanner) nextLine() string {
	return this.next()
}

