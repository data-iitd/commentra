
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
	var k, n int
	fmt.Fscanf(r, "%d%d\n", &k, &n)

	const mod = 998244353
	const maxN = 8000
	g1 := make([]int, maxN+1)
	g2 := make([]int, maxN+1)
	inv := make([]int, maxN+1)
	g1[0], g1[1] = 1, 1
	g2[0], g2[1] = 1, 1
	inv[1] = 1
	for i := 2; i <= maxN; i++ {
		g1[i] = int(int64(g1[i-1]) * int64(i) % mod)
		inv[i] = int(int64(-inv[mod%i]) * int64(mod/i) % mod)
		g2[i] = int(int64(g2[i-1]) * int64(inv[i]) % mod)
	}
	kumiawase := func(p, q int) int {
		if q < 0 || q > p {
			return 0
		}
		return int(int64(g1[p+q-1]) * int64(g2[q-1]) % mod * int64(g2[p-q]) % mod)
	}
	solve := func(n int) int {
		if n > k+1 {
			panic("n > k+1")
		}
		ans := 0
		kumi := (n - 1) / 2
		for p := 0; p <= kumi; p++ {
			if p > n {
				break
			}
			ans += (1 << p) * kumiawase(kumi, p) * kumiawase(n-p, p+(k-kumi*2-n%2))
			if n%2 == 0 && n-p-1 >= 0 {
				ans += (1 << p) * kumiawase(kumi, p) * kumiawase(n-p-1, p+(k-kumi*2-n%2))
			}
		}
		return ans
	}
	ans := make([]int, 2*k)
	for i := 2; i <= 2*k; i++ {
		if i <= k+1 {
			ans[i-2] = solve(i) % mod
			fmt.Fprintf(w, "%d\n", ans[i-2])
		} else {
			fmt.Fprintf(w, "%d\n", ans[i-2-k])
		}
	}
	w.Flush()
}

