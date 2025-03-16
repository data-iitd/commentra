
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
	const inf = 1 << 60
	var n, x int64
	fmt.Fscanf(r, "%d%d\n", &n, &x)
	xsum := make([]int64, n+1)
	for i := int64(0); i < n; i++ {
		var v int64
		fmt.Fscanf(r, "%d", &v)
		xsum[i+1] = xsum[i] + v
	}
	ans := x*n + 5*xsum[n]
	for i := int64(1); i < n; i++ {
		cost := x*i + 5*(xsum[n]-xsum[n-i])
		for j, k := int64(5), n-i; k >= 0; j += 2, k -= i {
			if cost > ans {
				break
			}
			cost += j * (xsum[k] - xsum[max(k-i, 0)])
		}
		ans = min(ans, cost)
	}
	fmt.Fprintf(w, "%d\n", ans+n*x)
	w.Flush()
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

// 