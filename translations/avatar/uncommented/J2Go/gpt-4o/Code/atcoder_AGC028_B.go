package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const mod = 1000000007

func main() {
	reader := bufio.NewReader(os.Stdin)
	nStr, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(nStr[:len(nStr)-1])
	saStr, _ := reader.ReadString('\n')
	sa := split(saStr[:len(saStr)-1], " ")
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(sa[i])
	}

	p := int64(1)
	for i := 2; i <= n; i++ {
		p = p * int64(i) % mod
	}

	q := make([]int64, n)
	q[0] = 1
	for i := 1; i < n; i++ {
		q[i] = (q[i-1] + modinv(int64(i+1), mod)) % mod
	}

	ans := int64(0)
	for i := 0; i < n; i++ {
		val := (q[i] + q[n-i-1] - 1) % mod
		val = (val * int64(a[i])) % mod
		val = (val * p) % mod
		ans = (ans + val) % mod
	}

	fmt.Println(ans)
}

func modinv(a, m int64) int64 {
	b := m
	u := int64(1)
	v := int64(0)
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

func split(s, sep string) []string {
	var result []string
	for _, v := range bufio.NewScanner(strings.NewReader(s)) {
		result = append(result, v.Text())
	}
	return result
}

// <END-OF-CODE>
