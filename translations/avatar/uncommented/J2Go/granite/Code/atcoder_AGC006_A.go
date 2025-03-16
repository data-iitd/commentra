
package main

import (
	"bufio"
	"fmt"
	"os"
)

const N = 200 + 10

var (
	f  [N]int
	b  [N]byte
	in = bufio.NewReader(os.Stdin)
	out= bufio.NewWriter(os.Stdout)
)

func getFail(b []byte, m int) {
	j := 0
	f[0], f[1] = 0, 0
	for i := 2; i <= m; i++ {
		for j > 0 && b[j+1]!= b[i] {
			j = f[j]
		}
		if b[j+1] == b[i] {
			j++
		}
		f[i] = j
	}
}

func main() {
	var n int
	fmt.Fscanf(in, "%d", &n)
	var s1, str string
	fmt.Fscanf(in, "%s", &s1)
	fmt.Fscanf(in, "%s", &str)
	cnt := 0
	for i := 0; i < n; i++ {
		b[cnt+1] = str[i]
		cnt++
	}
	for i := 0; i < n; i++ {
		b[cnt+1] = s1[i]
		cnt++
	}
	getFail(b, cnt)
	len := int(min(float64(f[cnt]), float64(n), float64(n)))
	fmt.Fprintf(out, "%d\n", 2*n-len)
	out.Flush()
}

func min(a, b, c float64) float64 {
	if a <= b && a <= c {
		return a
	} else if b <= a && b <= c {
		return b
	} else {
		return c
	}
}

