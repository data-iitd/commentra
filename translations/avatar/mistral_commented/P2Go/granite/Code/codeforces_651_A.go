

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
	var x, y int
	fmt.Fscanf(r, "%d %d\n", &x, &y)

	// Calculate and print the maximum value between x + y - 3 + ( ( y - x ) % 3 > 0 ) and 0
	fmt.Fprintf(w, "%d\n", max(x+y-3+((y-x)%3 > 0), 0))
	w.Flush()
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

