package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// A helper function to print output
func out(x ...interface{}) {
	fmt.Println(x...)
}

// Initialize a scanner for reading input
var sc = bufio.NewScanner(os.Stdin)

// Function to read an integer from the standard input
func getInt() int {
	sc.Scan()
	i, e := strconv.Atoi(sc.Text())
	if e != nil {
		panic(e)
	}
	return i
}

// Function to read a string from the standard input
func getString() string {
	sc.Scan()
	return sc.Text()
}

// Main function
func main() {
	// Initialize the scanner for reading input
	sc.Split(bufio.ScanWords)
	sc.Buffer([]byte{}, 1000000)

	// Read the number of elements 'n' and the number of queries 'q' from the standard input
	n, q := getInt(), getInt()

	// Initialize a Fenwick Tree of size 'n'
	fw := FenwickTree(n)

	// Iterate through each element and add it to the Fenwick Tree
	for i := 0; i < n; i++ {
		// Read an integer 'a' from the standard input and add it to the Fenwick Tree at index 'i'
		a := getInt()
		fw.Add(i, a)
	}

	// Iterate through each query
	for i := 0; i < q; i++ {
		// Read an integer 't' from the standard input to determine the type of query
		t := getInt()

		// If the query is of type 0, read two integers 'p' and 'x' from the standard input and add 'x' to the Fenwick Tree at index 'p'
		if t == 0 {
			p, x := getInt(), getInt()
			fw.Add(p, x)
		} else { // If the query is of type 1, read two integers 'l' and 'r' from the standard input and print the sum of elements in the range [l, r]
			l, r := getInt(), getInt()
			// Call the Sum function of the Fenwick Tree to get the sum of elements in the range [l, r]
			out(fw.Sum(l, r))
		}
	}
}

// ** copy from here to your source code **
//
// fenwick tree
//  1. go lang have no generics, so implement int(long long)
//  data type only.
//  2. do not care overflow
//

// BIT :
type BIT struct {
	n    int
	data []int
}

// FenwickTree :
func FenwickTree(n int) *BIT {
	var ret BIT
	ret.n = n
	ret.data = make([]int, n)
	return &ret
}

// Add :
func (b *BIT) Add(p, x int) {
	p++
	for p <= b.n {
		b.data[p-1] += x
		p += p & -p
	}
}

// Sum :
func (b *BIT) Sum(l, r int) int {
	return b.sum(r) - b.sum(l)
}

func (b *BIT) sum(r int) int {
	s := 0
	for r > 0 {
		s += b.data[r-1]
		r -= r & -r
	}
	return s
}
