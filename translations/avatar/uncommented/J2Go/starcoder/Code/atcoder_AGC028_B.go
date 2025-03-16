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
	n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	}
	mod := 1000000007
	p := 1
	for i := 2; i <= n; i++ {
		p = p * i % mod
	}
	q := make([]int, n)
	q[0] = 1
	for i := 1; i < n; i++ {
		q[i] = (q[i-1] + modinv(i+1, mod)) % mod
	}
	ans := 0
	for i := 0; i < n; i++ {
		val := q[i] + q[n-i-1] - 1
		val = (val * a[i]) % mod
		val = (val * p) % mod
		ans = (ans + val) % mod
	}
	fmt.Println(ans)
}

func modinv(a, m int) int {
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

