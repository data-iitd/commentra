package main

import "fmt"

func main() {
	var N int
	fmt.Scanf("%d", &N)

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
			ans %= mod
		}
	}

	fmt.Println(ans)
}

func isPrime(x int) bool {
	for i := 2; i*i <= x; i++ {
		if x%i == 0 {
			return false
		}
	}
	return true
}

