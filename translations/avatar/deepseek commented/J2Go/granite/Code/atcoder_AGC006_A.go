

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const N = 200 + 10

var (
	f  [N]int
	b  [N]byte
	in = bufio.NewReader(os.Stdin)
)

func getFail(b []byte, m int) {
	j := 0
	f[0] = f[1] = 0
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
	var s1, str string
	fmt.Fscanf(in, "%d\n", &n)
	fmt.Fscanf(in, "%s\n", &s1)
	fmt.Fscanf(in, "%s\n", &str)
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
	fmt.Println(2*n - len)
}

func min(a, b, c float64) float64 {
	if a <= b && a <= c {
		return a
	}
	if b <= a && b <= c {
		return b
	}
	return c
}

// END-OF-CODE