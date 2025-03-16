
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	mod := 1000000007
	p := 1
	for i := 2; i <= n; i++ {
		p = (p * i) % mod
	}

	q := make([]int64, n)
	q[0] = 1
	for i := 1; i < n; i++ {
		q[i] = (q[i-1] + modinv(int64(i+1), mod)) % mod
	}

	ans := int64(0)
	for i := 0; i < n; i++ {
		val := q[i] + q[n-i-1] - 1
		val *= int64(a[i])
		val %= mod
		val *= p
		val %= mod
		ans += val
		ans %= mod
	}

	fmt.Println(ans)
}

func modinv(a, m int64) int64 {
	b := m
	u := 1
	v := 0
	tmp := 0

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

