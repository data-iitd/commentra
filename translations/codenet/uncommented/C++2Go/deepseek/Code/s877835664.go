package main

import (
	"fmt"
)

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func lcm(a, b int) int {
	return a / gcd(a, b) * b
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

	sqrtNum := int(math.Sqrt(float64(num)))
	for i := 3; i <= sqrtNum; i += 2 {
		if num%i == 0 {
			return false
		}
	}

	return true
}

func modinv(a, m int) int {
	b := m
	u := 1
	v := 0
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
	var N, K int
	fmt.Scan(&N, &K)

	A := make([]int, N+1)
	for i := 1; i <= N; i++ {
		fmt.Scan(&A[i])
	}

	cur := 1
	dic := make(map[int]int)
	flg := false
	for i := 1; i <= K; i++ {
		if _, ok := dic[cur]; !ok || flg {
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

