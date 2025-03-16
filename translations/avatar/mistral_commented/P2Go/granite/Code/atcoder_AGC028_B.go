
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const MOD = 100000007

func main() {
	reader := bufio.NewReader(os.Stdin)
	N, _ := strconv.Atoi(reader.ReadLine()[2:])
	A := make([]int64, N)
	for i, v := range reader.ReadLine()[2:] {
		A[i], _ = strconv.Atoi(string(v))
	}
	M := 1000000
	fact := make([]int64, M)
	fact[0] = 1
	for n := 1; n < 1000; n++ {
		fact[n] = fact[n-1] * int64(n)
		fact[n] %= MOD
	}
	for n := 1; n < 1000; n++ {
		fact[n] *= fact[n-1]
		fact[n] %= MOD
	}
	inv := make([]int64, N)
	for i := 0; i < N; i++ {
		inv[i] = pow(int64(i+1), MOD-2, MOD)
	}
	invSum := make([]int64, N)
	invSum[N-1] = inv[N-1]
	for i := N - 2; i >= 0; i-- {
		invSum[i] = invSum[i+1] + inv[i]
		invSum[i] %= MOD
	}
	temp := make([]int64, N)
	for i := 0; i < N; i++ {
		temp[i] = invSum[i] + invSum[N-1-i] - 1
	}
	ans := int64(0)
	for i := 0; i < N; i++ {
		ans += A[i] * temp[i]
		ans %= MOD
	}
	ans *= fact[N]
	ans %= MOD
	fmt.Println(ans)
}

func pow(x, n, mod int64) int64 {
	y := int64(1)
	for n > 0 {
		if n&1 == 1 {
			y = y * x % mod
		}
		x = x * x % mod
		n >>= 1
	}
	return y
}

