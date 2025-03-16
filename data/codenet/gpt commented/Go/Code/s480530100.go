package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// out is a utility function to print output to the console.
func out(x ...interface{}) {
	fmt.Println(x...)
}

// Initialize a new scanner to read input from standard input.
var sc = bufio.NewScanner(os.Stdin)

// getInt reads an integer from input and returns it.
// It panics if the input cannot be converted to an integer.
func getInt() int {
	sc.Scan()
	i, e := strconv.Atoi(sc.Text())
	if e != nil {
		panic(e)
	}
	return i
}

// getString reads a string from input and returns it.
func getString() string {
	sc.Scan()
	return sc.Text()
}

func main() {
	// Set the scanner to split input by whitespace and allocate a large buffer.
	sc.Split(bufio.ScanWords)
	sc.Buffer([]byte{}, 1000000)

	// Read the number of elements (n) and the number of queries (q).
	n, q := getInt(), getInt()

	// Initialize a Fenwick Tree (Binary Indexed Tree) with n elements.
	fw := FenwickTree(n)

	// Read n integers and add them to the Fenwick Tree.
	for i := 0; i < n; i++ {
		a := getInt()
		fw.Add(i, a)
	}

	// Process q queries.
	for i := 0; i < q; i++ {
		t := getInt() // Read the type of query.
		if t == 0 {
			// For update queries, read position (p) and value (x) and update the Fenwick Tree.
			p, x := getInt(), getInt()
			fw.Add(p, x)
		} else {
			// For sum queries, read the range (l, r) and output the sum from l to r.
			l, r := getInt(), getInt()
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

// BIT represents a Binary Indexed Tree (Fenwick Tree).
type BIT struct {
	n    int     // Number of elements in the tree
	data []int   // Array to store the tree data
}

// FenwickTree initializes a new Binary Indexed Tree with n elements.
func FenwickTree(n int) *BIT {
	var ret BIT
	ret.n = n
	ret.data = make([]int, n) // Create a slice to hold the tree data
	return &ret
}

// Add updates the Fenwick Tree by adding x to the element at position p.
func (b *BIT) Add(p, x int) {
	p++ // Increment p to match the 1-based index used in Fenwick Tree
	for p <= b.n {
		b.data[p-1] += x // Update the tree data
		p += p & -p      // Move to the next index
	}
}

// Sum calculates the sum of elements in the range [l, r).
func (b *BIT) Sum(l, r int) int {
	return b.sum(r) - b.sum(l) // Return the difference of sums
}

// sum calculates the prefix sum from the start to index r.
func (b *BIT) sum(r int) int {
	s := 0 // Initialize sum
	for r > 0 {
		s += b.data[r-1] // Add the value at index r-1
		r -= r & -r      // Move to the parent index
	}
	return s // Return the calculated sum
}
