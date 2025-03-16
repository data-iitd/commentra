
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const MOD = 1000000007

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(reader.ReadLine()[2:])
	a := make([]int, n)
	for i, v := range reader.ReadLine()[2:] {
		a[i], _ = strconv.Atoi(string(v))
	}
	p := int64(1)
	for i := 2; i <= n; i++ {
		p = p * int64(i) % MOD
	}
	q := make([]int64, n)
	q[0] = 1
	for i := 1; i < n; i++ {
		q[i] = (q[i-1] + modinv(int64(i+1), MOD)) % MOD
	}
	ans := int64(0)
	for i := 0; i < n; i++ {
		val := (q[i]+q[n-i-1]-1)*int64(a[i]) % MOD
		val = val * p % MOD
		ans = (ans + val) % MOD
	}
	fmt.Println(ans)
}

func modinv(a, m int64) int64 {
	b, u, v := m, int64(1), int64(0)
	tmp := int64(0)
	for b > 0 {
		t := a / b
		a -= t * b
		tmp = a
		a = b
		b = tmp
		u -= t * v
		tmp = u
		u = v
		v = tmp
	}
	u %= m
	if u < 0 {
		u += m
	}
	return u
}

