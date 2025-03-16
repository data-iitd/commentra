
# Go:
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// out is a helper function to print output.
func out(x ...interface{}) {
	fmt.Println(x...)
}

// sc is a bufio.Scanner set up to read input in a word-by-word manner.
var sc = bufio.NewScanner(os.Stdin)

// getInt reads a single word from the input and converts it to an integer.
func getInt() int {
	sc.Scan()
	i, e := strconv.Atoi(sc.Text())
	if e != nil {
		panic(e)
	}
	return i
}

// getString reads a single word from the input and returns it as a string.
func getString() string {
	sc.Scan()
	return sc.Text()
}

// main function is the entry point of the program.
func main() {
	// Set the split function for the scanner to split by words.
	sc.Split(bufio.ScanWords)
	// Set the buffer size for the scanner to a large value.
	sc.Buffer([]byte{}, 1000000)

	// Read the number of elements (n) and the number of queries (q).
	n, q := getInt(), getInt()

	// Initialize a Fenwick Tree with n elements.
	fw := FenwickTree(n)

	// Read n elements and add them to the Fenwick Tree.
	for i := 0; i < n; i++ {
		a := getInt()
		fw.Add(i, a)
	}

	// Process q queries.
	for i := 0; i < q; i++ {
		t := getInt()
		if t == 0 {
			// Update the value at position p by adding x to it.
			p, x := getInt(), getInt()
			fw.Add(p, x)
		} else {
			// Query the sum of elements between indices l and r.
			l, r := getInt(), getInt()
			out(fw.Sum(l, r))
		}
	}
}

// Fenwick Tree implementation

// BIT represents the Fenwick Tree data structure.
type BIT struct {
	n    int
	data []int
}

// FenwickTree initializes and returns a new Fenwick Tree with a given size.
func FenwickTree(n int) *BIT {
	var ret BIT
	ret.n = n
	ret.data = make([]int, n)
	return &ret
}

// Add updates the value at position p by adding x to it.
func (b *BIT) Add(p, x int) {
	p++ // Convert to 1-based index
	for p <= b.n {
		b.data[p-1] += x
		p += p & -p // Move to the next node
	}
}

// Sum calculates the sum of elements between indices l and r.
func (b *BIT) Sum(l, r int) int {
	return b.sum(r) - b.sum(l)
}

// sum calculates the prefix sum up to index r.
func (b *BIT) sum(r int) int {
	s := 0
	for r > 0 {
		s += b.data[r-1]
		r -= r & -r // Move to the parent node
	}
	return s
}

