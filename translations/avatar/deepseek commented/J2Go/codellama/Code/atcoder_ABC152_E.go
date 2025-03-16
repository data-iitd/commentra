
package main

import (
	"fmt"
	"math/big"
	"os"
	"strconv"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	var N int
	sc.Scan()
	N, _ = strconv.Atoi(sc.Text())
	A := make([]int, N)
	for i := 0; i < N; i++ {
		sc.Scan()
		A[i], _ = strconv.Atoi(sc.Text())
	}
	sc.Close()
	lcm := big.NewInt(1)
	for _, ai := range A {
		a := big.NewInt(int64(ai))
		lcm.Div(lcm, lcm.GCD(nil, nil, a))
		lcm.Mul(lcm, a)
	}
	mod := int64(1000000007)
	modLcm := lcm.Int64() % mod
	ans := int64(0)
	for _, ai := range A {
		ans = (ans + modDiv(modLcm, ai, mod)) % mod
	}
	fmt.Println(ans)
}

func modDiv(a, b, mod int64) int64 {
	return (a % mod) * modInv(b, mod) % mod
}

func modInv(x, mod int64) int64 {
	return modPow(x, mod-2, mod)
}

func modPow(b, e, mod int64) int64 {
	ans := int64(1)
	x := b % mod
	for y := e; y != 0; y >>= 1 {
		if y&1 == 1 {
			ans = (ans * x) % mod
		}
		x = (x * x) % mod
	}
	return ans
}

// 