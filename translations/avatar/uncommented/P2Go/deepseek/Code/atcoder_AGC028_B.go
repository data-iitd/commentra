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
	input, _ := reader.ReadString('\n')
	N, _ := strconv.Atoi(input)

	input, _ = reader.ReadString('\n')
	A := make([]int64, N)
	for i := 0; i < N; i++ {
		fmt.Sscanf(input, "%d", &A[i])
	}

	Nsq := 1000
	M := 1000000
	fact := make([]int64, Nsq*Nsq)
	fact[0] = 1
	for n := 1; n < Nsq; n++ {
		for j := 0; j < Nsq; j++ {
			fact[n*Nsq+j] = fact[(n-1)*Nsq+j] * int64(n) % MOD
		}
	}
	for n := 1; n < Nsq; n++ {
		for j := 0; j < Nsq; j++ {
			fact[n*Nsq+j] = fact[n*Nsq+j] * fact[(n-1)*Nsq+j] % MOD
		}
	}

	inv := make([]int64, N)
	inv[0] = 1
	for i := 1; i < N; i++ {
		inv[i] = pow(int64(i+1), MOD-2, MOD)
	}
	for i := 1; i < N; i++ {
		inv[i] = (inv[i] + inv[i-1]) % MOD
	}

	var ans int64 = 0
	for i := 0; i < N; i++ {
		temp := (inv[i] + inv[N-1-i] - 1 + MOD) % MOD
		ans = (ans + A[i]*temp%MOD) % MOD
	}

	ans *= fact[N]
	ans %= MOD
	fmt.Println(ans)
}

func pow(base, exp, mod int64) int64 {
	result := int64(1)
	for exp > 0 {
		if exp%2 == 1 {
			result = result * base % mod
		}
		base = base * base % mod
		exp /= 2
	}
	return result
}

