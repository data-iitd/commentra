package main

import (
	"fmt"
	"math"
	"os"
)

const MOD = 1_000_000_007
const M = 1_000_000
const Nsq = 1_000

func main() {
	var N int
	fmt.Scan(&N)

	A := make([]int64, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
	}

	fact := make([]int64, Nsq*Nsq)
	fact[0] = 1

	for n := 1; n < Nsq; n++ {
		for i := 0; i < Nsq; i++ {
			fact[i*Nsq+n] = (fact[i*Nsq+n-1] * int64(i+1)) % MOD
		}
	}

	for n := 1; n < Nsq; n++ {
		for i := 0; i < Nsq; i++ {
			fact[n*Nsq+i] = (fact[n*Nsq+i] * fact[(n-1)*Nsq+Nsq-1]) % MOD
		}
	}

	j := make([]int, N)
	for i := 0; i < N; i++ {
		j[i] = i
	}

	inv := make([]int64, N)
	for i := 0; i < N; i++ {
		inv[i] = pow(int64(i+1), MOD-2, MOD)
	}

	for i := 1; i < N; i++ {
		inv[i] = (inv[i] + inv[i-1]) % MOD
	}

	temp := make([]int64, N)
	for i := 0; i < N; i++ {
		temp[i] = (inv[j[i]] + inv[N-1-j[i]] - 1 + MOD) % MOD
	}

	ans := int64(0)
	for i := 0; i < N; i++ {
		ans = (ans + A[i]*temp[i]) % MOD
	}

	ans = (ans * fact[N]) % MOD
	fmt.Println(ans)
}

func pow(x, y, p int64) int64 {
	res := int64(1)
	x = x % p
	for y > 0 {
		if y&1 == 1 {
			res = (res * x) % p
		}
		y = y >> 1
		x = (x * x) % p
	}
	return res
}

// <END-OF-CODE>
