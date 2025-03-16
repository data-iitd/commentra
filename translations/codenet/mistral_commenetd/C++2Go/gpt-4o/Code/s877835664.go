package main

import (
	"fmt"
	"math"
)

type Int64Slice []int64

// Function to calculate gcd
func gcd(a, b int64) int64 {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

// Function to calculate lcm
func lcm(a, b int64) int64 {
	return a / gcd(a, b) * b
}

// Function to get prime factors of a number
func getPrimeFactors(n int64) map[int64]int64 {
	res := make(map[int64]int64)
	for i := int64(2); i*i <= n; i++ {
		for n%i == 0 {
			res[i]++
			n /= i
		}
	}
	if n != 1 {
		res[n] = 1
	}
	return res
}

// Function to check if a number is prime
func isPrime(num int64) bool {
	if num <= 1 {
		return false
	}
	if num == 2 {
		return true
	}
	if num%2 == 0 {
		return false
	}
	sqrtNum := int64(math.Sqrt(float64(num)))
	for i := int64(3); i <= sqrtNum; i += 2 {
		if num%i == 0 {
			return false
		}
	}
	return true
}

// Function to find modular multiplicative inverse
func modinv(a, m int64) int64 {
	b, u, v := m, int64(1), int64(0)
	for b != 0 {
		t := a / b
		a -= t * b
		a, b = b, a
		u -= t * v
		u, v = v, u
	}
	u %= m
	if u < 0 {
		u += m
	}
	return u
}

func main() {
	var N, K int64
	fmt.Scan(&N, &K)

	A := make(Int64Slice, N+1)
	for i := int64(1); i <= N; i++ {
		fmt.Scan(&A[i])
	}

	cur := int64(1)
	dic := make(Int64Slice, N+1)
	for i := range dic {
		dic[i] = -1
	}

	flg := false
	for i := int64(1); i <= K; i++ {
		if dic[cur] < 0 || flg {
			dic[cur] = i
			cur = A[cur]
		} else if !flg {
			tmp := K - (dic[cur] - 1)
			tmp %= i - dic[cur]
			i = K - tmp
			flg = true
		}
	}

	fmt.Println(cur)
}

// <END-OF-CODE>
