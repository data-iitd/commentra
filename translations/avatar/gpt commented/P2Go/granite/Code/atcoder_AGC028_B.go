
package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
)

const MOD = 100000007

func main() {
	r := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(read(r))
	a := readInt64s(r, n)
	const M = 1000000
	fact := make([]int64, M)
	fact[0] = 1
	for i := 1; i < M; i++ {
		fact[i] = fact[i-1] * int64(i)
		fact[i] %= MOD
	}
	inv := make([]int64, n)
	for i := 0; i < n; i++ {
		inv[i] = pow(int64(i+1), MOD-2)
	}
	for i := 1; i < n; i++ {
		inv[i] += inv[i-1]
		inv[i] %= MOD
	}
	temp := make([]int64, n)
	for i := 0; i < n; i++ {
		temp[i] = inv[i] + inv[n-1-i] - 1
	}
	ans := int64(0)
	for i := 0; i < n; i++ {
		ans += a[i] * temp[i]
		ans %= MOD
	}
	ans *= fact[n]
	ans %= MOD
	fmt.Println(ans)
}

func read(r *bufio.Reader) string {
	str, _ := r.ReadString('\n')
	return str
}

func readInt64s(r *bufio.Reader, n int) []int64 {
	res := make([]int64, n)
	s, _ := r.ReadBytes('\n')
	for i := 0; i < n; i++ {
		res[i] = int64(mustParseInt(s[i*2 : i*2+2]))
	}
	return res
}

func mustParseInt(s string) int {
	n, err := strconv.Atoi(s)
	if err!= nil {
		panic(err)
	}
	return n
}

func pow(x, n int64) int64 {
	res := int64(1)
	for n > 0 {
		if n&1 == 1 {
			res = res * x % MOD
		}
		x = x * x % MOD
		n >>= 1
	}
	return res
}

