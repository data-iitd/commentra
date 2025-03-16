
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	const mod = 100000007
	r := bufio.NewReader(os.Stdin)

	var n int
	fmt.Fscanf(r, "%d\n", &n)

	c := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscanf(r, "%d", &c[i])
	}

	b := int(pow(2, 2*n-2, mod))
	a := 2 * b % mod

	ans := int64(0)
	for i := 0; i < n; i++ {
		ans += int64(c[i]) * (int64(a)+int64(i)*int64(b))
		ans %= mod
	}

	fmt.Println(ans)
}

func pow(x, n, mod int) int {
	y := 1
	for n > 0 {
		if n&1 == 1 {
			y = y * x % mod
		}
		x = x * x % mod
		n >>= 1
	}
	return y
}

