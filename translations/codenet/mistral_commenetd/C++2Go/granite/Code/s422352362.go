

package main

import (
	"bufio"
	"fmt"
	"os"
)

const MAX_N = 200005

var (
	n int
	a [MAX_N]int64
	pre [MAX_N]int64
	last [MAX_N]int64
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscanf(reader, "%d\n", &n)
	for i := 1; i <= n; i++ {
		fmt.Fscanf(reader, "%d\n", &a[i])
		pre[i] = pre[i-1] + a[i]
		last[i] = last[i+1] + a[i]
	}
	sumpre, sumlast := int64(0), int64(0)
	for i := 1; i < n; i++ {
		sumpre += a[i]
		pre[i] = sumpre
	}
	for i := n; i > 0; i-- {
		sumlast += a[i]
		last[i] = sumlast
	}
	d := int64(1 << 60)
	for i := 1; i < n; i++ {
		if abs(pre[i]-last[i+1]) < d {
			d = abs(pre[i] - last[i+1])
		}
	}
	fmt.Println(d)
}

func abs(x int64) int64 {
	if x < 0 {
		return -x
	}
	return x
}

