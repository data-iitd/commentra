
// ABC 152-D
// 2020.1.19 bal4u

package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	in  = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
)

func main() {
	var N int
	fmt.Fscanf(in, "%d\n", &N)

	f1 := make([]int, 100)
	f2 := make([]int, 100)
	for N >= 10 {
		k := N % 10
		for N >= 10 {
			N /= 10
		}
		f1[10*k+N]++
		f2[10*N+k]++
	}

	ans := 0
	for i := 0; i < 100; i++ {
		ans += f1[i] * f2[i]
	}
	fmt.Fprintf(out, "%d\n", ans)
	out.Flush()
}

