
package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

// Declaring static variables
var g [][]int // To store the graph
var maxMatching int // To store the maximum number of edges that can be matched in a bipartite graph

// Function to find the maximum number of edges that can be matched in a bipartite graph
func maxMatching(v int, p int) int {
	a := 0 // Number of edges matched from the neighboring vertices of 'v'
	o := 0 // Number of vertices that have odd degree (unmatched vertices) in the neighboring vertices of 'v'

	// Iterating through all the neighbors of 'v'
	for _, w := range g[v] {
		if w == p { // Skip if the neighbor is 'p' (self-loop)
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

// Function to find the minimum of two integers
func min(a int, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	// Creating an instance of MyScanner class for reading input
	sc := new(MyScanner)
	out := bufio.NewWriter(os.Stdout) // Creating an instance of PrintWriter for output

	// Reading the number of vertices in the graph
	n, _ := strconv.Atoi(sc.next())

	// Initializing the graph as an ArrayList of ArrayLists
	g = make([][]int, n)
	for i := 0; i < n; i++ {
		g[i] = make([]int, 0)
	}

	// Reading the edges and adding them to the graph
	for i := 0; i < n-1; i++ {
		a, _ := strconv.Atoi(sc.next()) // Reading the first vertex of the edge
		b, _ := strconv.Atoi(sc.next()) // Reading the second vertex of the edge
		g[a-1] = append(g[a-1], b-1)    // Adding the edge from 'a' to 'b'
		g[b-1] = append(g[b-1], a-1)    // Adding the edge from 'b' to 'a'
	}

	// Finding the maximum number of edges that can be matched in the graph
	maxMatching = maxMatching(0, -1) / 2

	// Printing the result based on whether all vertices have even degree or not
	fmt.Fprintln(out, "Second")
	if 2*maxMatching == n {
		fmt.Fprintln(out, "Second")
	} else {
		fmt.Fprintln(out, "First")
	}

	// Closing the output stream
	out.Flush()
}

type MyScanner struct {
	br *bufio.Reader
	st *strings.Reader
}

// Constructor for MyScanner class
func (sc *MyScanner) init() {
	sc.br = bufio.NewReader(os.Stdin)
}

// Function to read the next token from the input stream
func (sc *MyScanner) next() string {
	for sc.st == nil || !sc.st.Scan() {
		line, err := sc.br.ReadString('\n')
		if err != nil {
			if err == io.EOF {
				return ""
			}
			panic(err)
		}
		sc.st = strings.NewReader(line)
	}
	return sc.st.Text()
}

// Overloaded functions for reading different data types
func (sc *MyScanner) nextInt() int {
	i, _ := strconv.Atoi(sc.next())
	return i
}

func (sc *MyScanner) nextLong() int64 {
	i, _ := strconv.ParseInt(sc.next(), 10, 64)
	return i
}

func (sc *MyScanner) nextDouble() float64 {
	f, _ := strconv.ParseFloat(sc.next(), 64)
	return f
}

func (sc *MyScanner) nextLine() string {
	sc.st = nil
	return sc.next()
}

