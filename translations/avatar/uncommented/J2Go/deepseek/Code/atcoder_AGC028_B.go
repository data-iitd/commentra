package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(readLine(reader))
	sa := strings.Split(readLine(reader), " ")
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(sa[i])
	}
	mod := int(1e9 + 7)
	p := int64(1)
	for i := 2; i <= n; i++ {
		p = p * int64(i) % int64(mod)
	}
	q := make([]int64, n)
	q[0] = 1
	for i := 1; i < n; i++ {
		q[i] = (q[i-1] + modinv(i+1, mod)) % mod
	}
	ans := int64(0)
	for i := 0; i < n; i++ {
		val := q[i] + q[n-i-1] - 1
		val *= int64(a[i])
		val %= int64(mod)
		val *= p
		val %= int64(mod)
		ans += val
		ans %= int64(mod)
	}
	fmt.Println(ans)
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err != nil {
		panic(err)
	}
	return string(str)
}

func modinv(a, m int) int64 {
	b := int64(m)
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
	u %= int64(m)
	if u < 0 {
		u += int64(m)
	}
	return u
}

