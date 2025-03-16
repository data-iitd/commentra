package main

import (
	"fmt"
)

const mod = 1e9 + 7

func isPrime(x int64) bool {
	if x < 2 {
		return false
	}
	for i := int64(2); i*i <= x; i++ {
		if x%i == 0 {
			return false
		}
	}
	return true
}

func main() {
	var N int
	fmt.Scan(&N)

	ans := int64(1)
	for i := 2; i <= N; i++ {
		if isPrime(int64(i)) {
			NN := N
			cnt := 0
			for NN > 0 {
				cnt += NN / i
				NN /= i
			}
			ans = (ans * int64(cnt+1)) % mod
		}
	}

	fmt.Println(ans)
}

// <END-OF-CODE>
