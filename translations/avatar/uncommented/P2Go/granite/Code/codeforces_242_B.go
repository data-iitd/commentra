
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var (
	r = bufio.NewReader(os.Stdin)
	w = bufio.NewWriter(os.Stdout)
)

func main() {
	var n int
	fmt.Fscanf(r, "%d\n", &n)
	l, r := 0, 0
	id := 0
	for i := 0; i < n; i++ {
		li, ri := 0, 0
		fmt.Fscanf(r, "%d %d\n", &li, &ri)
		if li <= l && r <= ri {
			id = i + 1
		} else if li < l || r < ri {
			id = n
		}
		l = min(l, li)
		r = max(r, ri)
	}
	fmt.Fprintf(w, "%d\n", id)
	w.Flush()
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

