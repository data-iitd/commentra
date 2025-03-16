
package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	read  = bufio.NewReader(os.Stdin)
	write = bufio.NewWriter(os.Stdout)
)

func main() {
	var (
		N, d, x int
		res      int
	)
	fmt.Fscanf(read, "%d %d %d\n", &N, &d, &x)
	for N > 0 {
		res += d + (N-0.5)*x
		d += d/N + 5*x/(2*N)
		x += 2*x/N
		N--
	}
	fmt.Fprintf(write, "%d\n", res)
	write.Flush()
}

