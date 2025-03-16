
package main

import (
	"bufio"
	"fmt"
	"os"
)

const MOD = 100000007
const NMAX = 1000010

var fac, finv, inv [NMAX]int

func init() {
	fac[0] = fac[1] = 1
	finv[0] = finv[1] = 1
	inv[1] = 1
	for i := 2; i < NMAX; i++ {
		fac[i] = fac[i-1] * i % MOD
		inv[i] = MOD - inv[MOD%i]*(MOD/i)%MOD
		finv[i] = finv[i-1] * inv[i] % MOD
	}
}

func C(n, k int) int {
	if n < k {
		return 0
	}
	if n < 0 || k < 0 {
		return 0
	}
	return fac[n] * (finv[k] * finv[n-k] % MOD) % MOD
}

func main() {
	sc := bufio.NewScanner(os.Stdin)
	buf := make([]byte, 0)
	sc.Buffer(buf, 1010000)
	sc.Split(bufio.ScanWords)

	X, Y := nextInt(sc), nextInt(sc)
	if (X+Y)%3!= 0 {
		fmt.Println(0)
		return
	}
	n := (X + Y) / 3 + 1
	k := 2*(n-1) - Y + 1
	fmt.Println(C(n-1, k-1))
}

func nextInt(sc *bufio.Scanner) int {
	sc.Scan()
	i, _ := strconv.Atoi(sc.Text())
	return i
}

