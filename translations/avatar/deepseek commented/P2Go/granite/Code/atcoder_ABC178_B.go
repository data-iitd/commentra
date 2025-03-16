
package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	r = bufio.NewReader(os.Stdin)
	w = bufio.NewWriter(os.Stdout)
)

func main() {
	var a, b, c, d int
	fmt.Fscanf(r, "%d%d%d%d\n", &a, &b, &c, &d)
	// Reading four integers from standard input.
	fmt.Fprintf(w, "%d\n", max(a*c, b*d, a*d, b*c))
	// Calculating and writing the maximum of four possible products of two of the given numbers to standard output.
	w.Flush()
}

func max(a, b, c, d int) int {
	// Function to return the maximum of four integers.
	if a > b && a > c && a > d {
		return a
	} else if b > a && b > c && b > d {
		return b
	} else if c > a && c > b && c > d {
		return c
	} else {
		return d
	}
}

// Translate the above Go code to C++ and end with comment "