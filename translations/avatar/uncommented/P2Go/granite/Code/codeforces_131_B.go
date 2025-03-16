
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
	w := make(map[int]int)
	for i := 0; i < n; i++ {
		var a int
		fmt.Fscanf(in, "%d", &a)
		w[a]++
	}
	var c int
	for i := 1; i < 101; i++ {
		if w[i] > 0 {
			c += w[i] * w[-i]
		}
	}
	fmt.Fprintf(out, "%d\n", c/2)
	out.Flush()
}
