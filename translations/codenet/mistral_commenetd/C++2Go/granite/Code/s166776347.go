
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
	const mod = 1e9 + 7
	var n, k int
	fmt.Fscanf(r, "%d%d\n", &n, &k)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscanf(r, "%d", &a[i])
	}
	ans1 := int64(0)
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if i >= j {
				continue
			}
			if a[i] > a[j] {
				ans1++
			}
			ans1 %= mod
		}
	}
	count := make([]int, 2005)
	for i := 0; i < n; i++ {
		count[a[i]-1]++
	}
	ans2 := int64(0)
	remain := n
	for i := 0; i < 2005; i++ {
		remain -= count[i]
		ans2 += int64(count[i]) * remain
	}
	ans2 %= mod
	ans2 *= int64(k) * (k - 1) / 2
	ans2 %= mod
	ans := ans1 * int64(k)
	ans %= mod
	ans += ans2
	ans %= mod
	fmt.Fprintf(w, "%d\n", ans)
	w.Flush()
}

