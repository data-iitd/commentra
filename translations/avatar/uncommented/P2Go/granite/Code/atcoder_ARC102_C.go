
package main

import (
	"bufio"
	"bytes"
	"fmt"
	"os"
)

var (
	r = bufio.NewReader(os.Stdin)
	w = bufio.NewWriter(os.Stdout)
)

func main() {
	var k, n int
	fmt.Fscanf(r, "%d%d\n", &k, &n)
	mod := 998244353
	const N = 8000
	g1 := make([]int, N+1)
	g2 := make([]int, N+1)
	inverse := make([]int, N+1)
	g1[0], g1[1] = 1, 1
	g2[0], g2[1] = 1, 1
	inverse[0], inverse[1] = 0, 1
	for i := 2; i <= N; i++ {
		g1[i] = (int64(g1[i-1]) * int64(i)) % mod
		inverse[i] = (int64(-inverse[mod%i]) * int64(mod/i)) % mod
		g2[i] = (int64(g2[i-1]) * int64(inverse[i])) % mod
	}
	kumiawase := func(p, q int) int {
		return int((int64(g1[p+q-1]) * int64(g2[q-1]) % mod) * int64(g2[p-1]) % mod)
	}
	solve := func(n int) int {
		assert(n <= k+1)
		ans := 0
		kumi := (n - 1) / 2
		for p := 0; p <= kumi; p++ {
			if p > n {
				break
			}
			ans += (1 << p) * kumiawase(n-p, p+(k-kumi*2-int(n%2 == 0))) * int(g1[kumi]) * int(g2[p]) % mod * int(g2[kumi-p]) % mod
			if n%2 == 0 && n-p-1 >= 0 {
				ans += (1 << p) * kumiawase(n-p-1, p+(k-kumi*2-int(n%2 == 0))) * int(g1[kumi]) * int(g2[p]) % mod * int(g2[kumi-p]) % mod
			}
		}
		return ans
	}
	ans := make([]int, 2*k)
	for i := 2; i <= 2*k; i++ {
		if i <= k+1 {
			tmp := solve(i) % mod
			ans[i-2] = tmp
			fmt.Fprintf(w, "%d\n", tmp)
		} else {
			fmt.Fprintf(w, "%d\n", ans[i-2-k])
		}
	}
	w.Flush()
}

func assert(b bool) {
	if!b {
		panic("Assertion failed")
	}
}