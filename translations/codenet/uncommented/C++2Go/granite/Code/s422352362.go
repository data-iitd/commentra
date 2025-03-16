
package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	r = bufio.NewReader(os.Stdin)
	w = bufio.NewWriter(os.Stdout)
)

func main() {
	var n int
	fmt.Fscanf(r, "%d\n", &n)
	a := make([]int64, n+1)
	for i := 1; i <= n; i++ {
		fmt.Fscanf(r, "%d\n", &a[i])
	}
	pre := make([]int64, n+1)
	last := make([]int64, n+1)
	sumpre := int64(0)
	sumlast := int64(0)
	for i := 1; i < n; i++ {
		sumpre += a[i]
		pre[i] = sumpre
	}
	for i := n; i > 1; i-- {
		sumlast += a[i]
		last[i] = sumlast
	}
	d := int64(1) << 60
	for i := 1; i < n; i++ {
		d = min(d, abs(pre[i]-last[i+1]))
	}
	fmt.Fprintf(w, "%d\n", d)
	w.Flush()
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func abs(a int64) int64 {
	if a < 0 {
		return -a
	}
	return a
}

