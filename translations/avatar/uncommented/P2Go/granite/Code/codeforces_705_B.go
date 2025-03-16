
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var (
	in  = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
)

func main() {
	var n int
	fmt.Fscanf(in, "%d\n", &n)
	w := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscanf(in, "%d", &w[i])
	}
	c := 2
	for i := 0; i < n; i++ {
		if w[i] == 1 {
			fmt.Fprintf(out, "%d\n", c)
		} else if w[i]%2 == 0 {
			c = 3 - c
			fmt.Fprintf(out, "%d\n", c)
		} else {
			fmt.Fprintf(out, "%d\n", c)
		}
	}
	out.Flush()
}
