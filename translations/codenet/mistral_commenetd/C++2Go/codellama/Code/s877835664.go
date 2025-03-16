
package main

import (
	"fmt"
	"math"
)

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func lcm(a, b int) int {
	return a * b / gcd(a, b)
}

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

func IsPrimeNumber(num int) bool {
	if num <= 2 {
		return true
	} else if num%2 == 0 {
		return false
	}

	sqrtNum := math.Sqrt(float64(num))
	for i := 3; i <= sqrtNum; i += 2 {
		if num%i == 0 {
			return false
		}
	}
	return true
}

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

func main() {
	var N, K int
	fmt.Scan(&N, &K)

	A := make([]int, N+1)
	for i := 1; i <= N; i++ {
		fmt.Scan(&A[i])
	}

	cur := 1
	dic := make([]int, N+1)
	for i := 1; i <= N; i++ {
		dic[cur] = i
		cur = A[cur]
	}

	fmt.Println(cur)
}

