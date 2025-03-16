package main

import (
	"fmt"
)

func main() {
	const MAX_V = 999999
	prime := make([]int, MAX_V+1)
	for i := 0; i <= MAX_V; i++ {
		prime[i] = 1
	}

	for i := 2; i <= MAX_V; i++ {
		if prime[i] == 1 {
			for k := i * i; k <= MAX_V; k += i {
				prime[k] = 0
			}
		}
	}

	prime[0] = 0
	prime[1] = 0

	count := 0
	var n int

	for {
		_, err := fmt.Scan(&n)
		if err != nil {
			break
		}

		count++
		cnt := 0

		for i := n; i > 0; i /= 10 {
			digit := i % 10
			if prime[digit] == 1 {
				cnt++
			}
		}

		fmt.Println(cnt)

		if count == 30 {
			break
		}
	}
}

