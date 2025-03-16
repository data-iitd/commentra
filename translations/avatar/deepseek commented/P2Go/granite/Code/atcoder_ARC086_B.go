
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
	var n int
	fmt.Fscanf(r, "%d\n", &n)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscanf(r, "%d", &a[i])
	}
	maxVal := 0
	maxIdx := -1
	for i, v := range a {
		if abs(v) > maxVal {
			maxVal = abs(v)
			maxIdx = i
		}
	}
	if maxVal == 0 {
		fmt.Fprintln(w, 0)
	} else {
		fmt.Fprintln(w, 2*n-1)
		for i := 0; i < n; i++ {
			fmt.Fprintf(w, "%d %d\n", maxIdx+1, i+1)
		}
		for i := 0; i < n-1; i++ {
			fmt.Fprintf(w, "%d %d\n", i+1, i+2)
		}
	}
	w.Flush()
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

