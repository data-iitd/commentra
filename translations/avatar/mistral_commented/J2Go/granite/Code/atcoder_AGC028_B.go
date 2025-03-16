

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	const mod = 1000000007
	reader := bufio.NewReader(os.Stdin)

	nStr, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(nStr)

	aStr, _ := reader.ReadString('\n')
	aStr = aStr[:len(aStr)-1] // Remove the trailing newline character
	a := make([]int, n)

	for i, v := range strings.Split(aStr, " ") {
		a[i], _ = strconv.Atoi(v)
	}

	p := int64(1)
	for i := 2; i <= n; i++ {
		p = (p * int64(i)) % mod
	}

	q := make([]int64, n)
	q[0] = 1

	for i := 1; i < n; i++ {
		q[i] = (q[i-1] + modinv(int64(i+1), mod)) % mod
	}

	ans := int64(0)
	for i := 0; i < n; i++ {
		val := (q[i] + q[n-i-1] - 1) * int64(a[i]) % mod
		val = val * p % mod
		ans = (ans + val) % mod
	}

	fmt.Println(ans)
}

func modinv(a, m int64) int64 {
	b := m
	u := int64(1)
	v := int64(0)

	for b > 0 {
		t := a / b
		a -= t * b
		tmp := a
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

