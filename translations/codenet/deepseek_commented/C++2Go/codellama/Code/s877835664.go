package main

import (
	"fmt"
	"math"
)

// Function to calculate the greatest common divisor (GCD)
func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

// Function to calculate the least common multiple (LCM)
func lcm(a, b int) int {
	return a / gcd(a, b) * b
}

// Function to get the prime factors of a number
func getPrimeFactor(n int) map[int]int {
	res := make(map[int]int)
	for i := 2; i*i <= n; i++ {
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

// Function to check if a number is a prime number
func IsPrimeNumber(num int) bool {
	if num <= 2 {
		return true
	} else if num%2 == 0 {
		return false
	}

	sqrtNum := math.Sqrt(float64(num))
	for i := 3; i <= int(sqrtNum); i += 2 {
		if num%i == 0 {
			return false
		}
	}

	return true
}

// Function to calculate the modular inverse of a number
func modinv(a, m int) int {
	b, u, v := m, 1, 0
	for b != 0 {
		t := a / b
		a, b = b, a%b
		u, v = v, u-t*v
	}
	u %= m
	if u < 0 {
		u += m
	}
	return u
}

// Macro for looping from s to e
func rep(i, s, e int) {
	for i = s; i < e; i++ {
	}
}

// Macro for looping from s to e inclusive
func repeq(i, s, e int) {
	for i = s; i <= e; i++ {
	}
}

func main() {
	var N, K int
	fmt.Scan(&N, &K)

	// Vector to store N+1 integers
	A := make([]int, N+1)
	repeq(i, 1, N) {
		fmt.Scan(&A[i])
	}

	// Variables to track the current position and the dictionary
	cur := 1
	dic := make([]int, N+1)
	flg := false
	repeq(i, 1, K) {
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

	// Output the final position
	fmt.Println(cur)
}

