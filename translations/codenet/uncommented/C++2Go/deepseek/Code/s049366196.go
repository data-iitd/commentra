package main

import (
	"fmt"
)

func isPrime(x int) bool {
	for i := 2; i*i <= x; i++ {
		if x%i == 0 {
			return false
		}
	}
	return true
}

func main() {
	var N int
	fmt.Scan(&N)

	ans := 1
	for i := 2; i <= N; i++ {
		if isPrime(i) {
			NN := N
			cnt := 0
			for NN > 0 {
				cnt += NN / i
				NN /= i
			}
			ans *= cnt + 1
			ans %= 1000000007
		}
	}

	fmt.Println(ans)
}

