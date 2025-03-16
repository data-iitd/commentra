
package main

import (
	"bufio"
	"fmt"
	"os"
)

const MOD = 100000007

var fac, finv, inv []int

func init() {
	fac = make([]int, 1000010)
	finv = make([]int, 1000010)
	inv = make([]int, 1000010)

	fac[0] = 1
	fac[1] = 1
	finv[0] = 1
	finv[1] = 1
	inv[1] = 1

	for i := 2; i < 1000010; i++ {
		fac[i] = fac[i-1] * i % MOD
		inv[i] = MOD - inv[MOD%i]*(MOD/i)%MOD
		finv[i] = finv[i-1] * inv[i] % MOD
	}
}

func comb(n, k int) int {
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
	sc.Split(bufio.ScanWords)
	sc.Scan()
	X := nextInt(sc)
	sc.Scan()
	Y := nextInt(sc)

	if (X+Y)%3!= 0 {
		fmt.Println(0)
		return
	}
	n := (X + Y) / 3 + 1
	k := 2*(n-1) - Y + 1 // y = 2xより最も上にくる点からどれだけ離れているか。
	fmt.Println(comb(n-1, k-1))
}

func nextInt(sc *bufio.Scanner) int {
	sc.Scan()
	i, _ := strconv.Atoi(sc.Text())
	return i
}

