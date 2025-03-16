
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
	var n int
	fmt.Fscanf(in, "%d\n", &n)
	f1 := make([]int, 100)
	f2 := make([]int, 100)
	for n > 0 {
		k := n % 10
		for n >= 10 {
			n /= 10
		}
		f1[10*k+n]++
		f2[n*10+k]++
		n--
	}
	ans := 0
	for i := 0; i < 100; i++ {
		ans += f1[i] * f2[i]
	}
	fmt.Fprintf(out, "%d\n", ans)
	out.Flush()
}

