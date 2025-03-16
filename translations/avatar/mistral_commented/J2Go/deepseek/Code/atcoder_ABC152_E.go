package main

import (
	"bufio"
	"fmt"
	"math/big"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	scanner.Scan()
	N := toInt(scanner.Text())
	A := make([]int, N)

	for i := 0; i < N; i++ {
		scanner.Scan()
		A[i] = toInt(scanner.Text())
	}

	lcm := big.NewInt(1)

	for _, ai := range A {
		a := big.NewInt(int64(ai))
		lcm.Div(lcm, lcm.GCD(nil, nil, lcm, a)).Mul(lcm, a)
	}

	mod := int64(1000000007)
	modLcm := new(big.Int).Mod(lcm, big.NewInt(mod)).Int64()

	ans := int64(0)

	for _, ai := range A {
		ans = (ans + modDiv(modLcm, int64(ai), mod)) % mod
	}

	fmt.Println(ans)
}

func toInt(s string) int {
	var num int
	fmt.Sscanf(s, "%d", &num)
	return num
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
	for y := e; y > 0; y >>= 1 {
		if y&1 == 1 {
			ans = (ans * x) % mod
		}
		x = (x * x) % mod
	}
	return ans
}

