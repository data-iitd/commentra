
package main

import (
	"bufio"
	"fmt"
	"os"
)

const MOD = 1000000007

func mod_pow(x, n int64) int64 {
	ans := int64(1)
	for n > 0 {
		if n&1 == 1 {
			ans = ans * x % MOD
		}
		x = x * x % MOD
		n >>= 1
	}
	return ans
}

func comb_s(n, r int64) int64 {
	tmp_n := int64(1)
	tmp_d := int64(1)
	ans := int64(0)
	for i := int64(1); i <= r; i++ {
		tmp_n = (tmp_n * (n + 1 - i)) % MOD
		tmp_d = (tmp_d * i) % MOD
		ans = tmp_n * mod_pow(tmp_d, MOD-2)
	}

	return ans
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	const initialBufSize = 4096
	const maxBufSize = 1000000
	scanner.Buffer(make([]byte, initialBufSize), maxBufSize)
	scanner.Split(bufio.ScanWords)
	var n, a, b int64
	scanner.Scan()
	n = nextInt64(scanner.Text())
	scanner.Scan()
	a = nextInt64(scanner.Text())
	scanner.Scan()
	b = nextInt64(scanner.Text())
	ans := mod_pow(2, n)
	ans--
	tmp_nd := comb_s(n, a)
	ans = (ans - tmp_nd) % MOD
	for ans < 0 {
		ans += MOD
	}
	tmp_nd = comb_s(n, b)
	ans = (ans - tmp_nd) % MOD
	for ans < 0 {
		ans += MOD
	}

	fmt.Println(ans)
}

func nextInt64(sc string) int64 {
	i, err := strconv.ParseInt(sc, 10, 64)
	if err!= nil {
		panic(err)
	}
	return i
}

