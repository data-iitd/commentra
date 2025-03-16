
package main

import (
	"bufio"
	"bytes"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	var q, h, s, d int
	fmt.Fscanf(reader, "%d %d %d %d\n", &q, &h, &s, &d)

	var n int
	fmt.Fscanf(reader, "%d\n", &n)

	best1L := min(q*4, h*2, s)
	best2L := min(d, best1L*2)

	var buf bytes.Buffer
	if n%2 == 0 {
		fmt.Fprintf(&buf, "%d\n", best2L*(n/2))
	} else {
		fmt.Fprintf(&buf, "%d\n", best2L*(n/2)+best1L)
	}
	fmt.Print(buf.String())
}

func min(a, b, c int) int {
	m := a
	if m > b {
		m = b
	}
	if m > c {
		m = c
	}
	return m
}

// Translate the above Go code to Rust and end with comment "