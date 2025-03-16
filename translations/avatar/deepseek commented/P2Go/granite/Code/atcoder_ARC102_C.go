
package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	readWriter = bufio.NewReadWriter(bufio.NewReader(os.Stdin), bufio.NewWriter(os.Stdout))
	mod         = 998244353
	N           = 8000
	g1          = []int{1, 1}
	g2          = []int{1, 1}
	inverse     = []int{0, 1}
)

func init() {
	for i := 2; i <= N; i++ {
		g1 = append(g1, (g1[i-1]*i)%mod)
		inverse = append(inverse, (-inverse[mod%i]*(mod/i))%mod)
		g2 = append(g2, (g2[i-1]*inverse[i])%mod)
	}
}

func cmb(n, r int) int {
	if r < 0 || r > n {
		return 0
	}
	r = min(r, n-r)
	return (g1[n]*g2[r])%mod * g2[n-r] % mod
}

func kumiawase(p, q int) int {
	return cmb(p+q-1, q-1)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func solve(n int) int {
	if n > K+1 {
		return ans[K-n+2]
	}
	ans := 0
	kumi := (n - 1) / 2
	for p := 0; p <= kumi; p++ {
		if p > N {
			break
		}
		ans += (1 << p) * cmb(kumi, p) * kumiawase(N-p, p+(K-kumi*2-int(n%2 == 0)))
		if n%2 == 0 && N-p-1 >= 0 {
			ans += (1 << p) * cmb(kumi, p) * kumiawase(N-p-1, p+(K-kumi*2-int(n%2 == 0)))
		}
	}
	return ans % mod
}

func main() {
	var K, N int
	fmt.Fscanf(readWriter, "%d %d\n", &K, &N)
	ans := make([]int, K+2)
	for i := 2; i <= 2*K; i++ {
		if i <= K+1 {
			ans[i] = solve(i)
			fmt.Fprintln(readWriter, ans[i])
		} else {
			fmt.Fprintln(readWriter, ans[K-i+2])
		}
	}
	readWriter.Flush()
}

