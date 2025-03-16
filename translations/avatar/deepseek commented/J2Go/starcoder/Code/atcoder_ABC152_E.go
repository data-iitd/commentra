
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the number of elements in the array")
	N, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	A := make([]int, N)
	fmt.Println("Enter the elements of the array")
	for i := 0; i < N; i++ {
		A[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	}
	lcm := big.NewInt(1)
	for _, ai := range A {
		a := big.NewInt(int64(ai))
		lcm.Div(lcm.GCD(lcm, a), lcm.GCD(lcm, a))
		lcm.Mul(lcm, a)
	}
	mod := int64(1000000007)
	modLcm := lcm.Mod(lcm, big.NewInt(mod)).Int64()
	ans := int64(0)
	for _, ai := range A {
		ans = (ans + modDiv(modLcm, int64(ai), mod)) % mod
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
	for y := e; y!= 0; y >>= 1 {
		if y&1 == 1 {
			ans = (ans * x) % mod
		}
		x = (x * x) % mod
	}
	return ans
}

