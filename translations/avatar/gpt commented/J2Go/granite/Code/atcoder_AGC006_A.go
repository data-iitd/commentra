
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const N = 200 + 10

var f [N]int
var b [N]byte

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
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	n, _ := strconv.Atoi(in.ReadLine()[2:])
	s1 := in.ReadLine()[2:]
	str := in.ReadLine()[2:]
	cnt := 0
	for i := 0; i < n; i++ {
		b[cnt+1] = str[i]
		cnt++
	}
	for i := 0; i < n; i++ {
		b[cnt+1] = s1[i]
		cnt++
	}
	getFail(b[:cnt+1], cnt)
	len := int(min(float64(f[cnt]), float64(min(n, n))))
	fmt.Fprintf(out, "%d\n", 2*n-len)
}

func min(a, b float64) float64 {
	if a < b {
		return a
	}
	return b
}

// END-OF-CODE