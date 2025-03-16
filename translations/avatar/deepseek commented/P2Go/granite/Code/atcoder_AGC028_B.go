

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
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(read(reader))
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(read(reader))
	}
	const Nsq = 1000
	fact := make([]int, Nsq*Nsq)
	fact[0] = 1
	for n := 1; n < Nsq; n++ {
		fact[n] = int(int64(fact[n-1]) * int64(n) % MOD)
	}
	for n := 1; n < Nsq; n++ {
		fact[n*Nsq] = int(int64(fact[n*Nsq-Nsq]) * int64(fact[Nsq-1]) % MOD)
	}
	inv := make([]int, n)
	inv[n-1] = 1
	for i := n - 2; i >= 0; i-- {
		inv[i] = int(int64(inv[i+1]) * int64(i+1) % MOD)
	}
	for i := 0; i < n; i++ {
		inv[i] = int(int64(inv[i]) * int64(inv[i]) % MOD)
	}
	for i := 1; i < n; i++ {
		inv[i] = int(int64(inv[i-1]) + int64(inv[i]) - 1)
	}
	temp := make([]int, n)
	for i := 0; i < n; i++ {
		temp[i] = int(int64(inv[i]) + int64(inv[n-1-i]) - 1)
	}
	ans := int64(0)
	for i := 0; i < n; i++ {
		ans += int64(a[i]) * int64(temp[i])
	}
	ans %= MOD
	ans *= int64(fact[n])
	ans %= MOD
	fmt.Println(ans)
}

func read(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return string(str)
}

