package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
)

func main() {
	var N int
	fmt.Scan(&N)
	A := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
	}
	M := 1000000
	Nsq := 1000
	fact := make([]int, Nsq*Nsq)
	fact[0] = 1
	for n := 1; n < Nsq; n++ {
		for i := 0; i < Nsq; i++ {
			fact[n*Nsq+i] = (fact[n*Nsq+i-1] + fact[n*Nsq+i]) % M
		}
	}
	for n := 1; n < Nsq; n++ {
		for i := 0; i < Nsq; i++ {
			fact[n*Nsq+i] = (fact[n*Nsq+i] + fact[(n-1)*Nsq+i]) % M
		}
	}
	fact = fact[:Nsq*Nsq]
	j := make([]int, N)
	for i := 0; i < N; i++ {
		j[i] = i
	}
	inv := make([]int, N)
	for i := 0; i < N; i++ {
		inv[i] = int(math.Pow(float64(i+1), float64(M-2))) % M
	}
	inv = append(inv, inv[:N]...)
	temp := make([]int, N)
	for i := 0; i < N; i++ {
		temp[i] = (inv[j[i]] + inv[N-1-j[i]] - 1) % M
	}
	ans := 0
	for i := 0; i < N; i++ {
		ans += A[i] * temp[i] % M
		ans %= M
	}
	ans *= fact[N]
	ans %= M
	fmt.Println(ans)
}

