
package main

import (
	"bufio"
	"fmt"
	"math/big"
	"os"
	"strconv"
)

func main() {
	const mod = 10000000007
	scanner := bufio.NewScanner(os.Stdin)
	const initialCapacity = 100000
	var buf [initialCapacity]byte
	scanner.Buffer(buf[:], initialCapacity)
	scanner.Split(bufio.ScanWords)
	var n int
	scanner.Scan()
	n, _ = strconv.Atoi(scanner.Text())
	a := make([]int, n)
	for i := 0; i < n; i++ {
		scanner.Scan()
		a[i], _ = strconv.Atoi(scanner.Text())
	}
	scanner.Scan()
	scanner.Scan()
	lcm := big.NewInt(1)
	for _, ai := range a {
		lcm.Div(lcm, lcm.GCD(nil, nil, big.NewInt(int64(ai))))
		lcm.Mul(lcm, big.NewInt(int64(ai)))
	}
	modLcm := lcm.Mod(lcm, big.NewInt(mod))
	ans := int64(0)
	for _, ai := range a {
		ans = (ans + modDiv(modLcm, int64(ai), mod)) % mod
	}
	fmt.Println(ans)
}

func modDiv(a, b, mod int64) int64 {
	return (a * modInv(b, mod)) % mod
}

func modInv(x, mod int64) int64 {
	return modPow(x, mod-2, mod)
}

func modPow(b, e, mod int64) int64 {
	ans := int64(1)
	x := b % mod
	for y := e; y!= 0; y >>= 1 {
		if y&1 == 1 {
			ans = (ans * x) % mod
		}
		x = (x * x) % mod
	}
	return ans
}

