
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	const mod = 998244353
	const N = 8000

	var k, n int
	fmt.Fscanf(bufio.NewReader(os.Stdin), "%d%d", &k, &n)

	g1 := make([]int, N+1)
	g2 := make([]int, N+1)
	inverse := make([]int, N+1)

	g1[0], g1[1] = 1, 1
	g2[0], g2[1] = 1, 1
	inverse[0], inverse[1] = 0, 1

	for i := 2; i <= N; i++ {
		g1[i] = (g1[i-1] * i) % mod
		inverse[i] = (-inverse[mod%i]*(mod/i)) % mod
		g2[i] = (g2[i-1] * inverse[i]) % mod
	}

	kumiawase := func(p, q int) int {
		return (g1[p+q-1] * g2[q-1] * g2[p]) % mod
	}

	solve := func(n int) int {
		if n <= 0 {
			return 0
		}
		if n > 2*k {
			return 0
		}
		kumi := (n - 1) / 2
		ans := 0
		for p := 0; p <= kumi; p++ {
			if p > N {
				break
			}
			ans += (1 << p) * kumiawase(N-p, p+(k-kumi*2-n%2))
			if n%2 == 0 && N-p-1 >= 0 {
				ans += (1 << p) * kumiawase(N-p-1, p+(k-kumi*2-n%2))
			}
		}
		return ans % mod
	}

	ans := make([]int, 2*k)
	for i := 2; i <= 2*k; i++ {
		ans[i-2] = solve(i)
		fmt.Println(ans[i-2])
	}
	for i := 2; i <= 2*k; i++ {
		if i <= k+1 {
			fmt.Println(ans[i-k-2])
		} else {
			fmt.Println(ans[2*k-i])
		}
	}
}

