
package main

import (
	"fmt"
	"math"
	"math/big"
	"os"
	"strconv"
	"strings"
)

const MOD = 1000000007

func main() {
	N := readInt()
	A := readInts()

	Nsq := 1000
	fact := make([][]int, Nsq)
	for i := range fact {
		fact[i] = make([]int, Nsq)
	}
	fact[0][0] = 1

	for n := 1; n < Nsq; n++ {
		for i := 0; i < Nsq; i++ {
			fact[i][n] = (fact[i][n-1] * fact[i][n-1]) % MOD
		}
	}

	for n := 1; n < Nsq; n++ {
		for i := 0; i < Nsq; i++ {
			fact[n][i] = (fact[n-1][i] * fact[n-1][Nsq-1]) % MOD
		}
	}

	inv := make([]int, N)
	for i := range inv {
		inv[i] = int(math.Pow(float64(i+1), MOD-2)) % MOD
	}
	inv = append(inv, inv[0])

	temp := make([]int, N)
	for i := range temp {
		temp[i] = (inv[i] + inv[N-1-i] - 1) % MOD
	}

	ans := 0
	for i := range A {
		ans += (A[i] * temp[i]) % MOD
	}
	ans %= MOD

	ans *= fact[N][N-1]
	ans %= MOD

	fmt.Println(ans)
}

func readInt() int {
	var n int
	fmt.Scan(&n)
	return n
}

func readInts() []int {
	var s string
	fmt.Scan(&s)
	return toInts(strings.Split(s, " "))
}

func toInts(s []string) []int {
	ns := make([]int, len(s))
	for i, v := range s {
		ns[i], _ = strconv.Atoi(v)
	}
	return ns
}

// 