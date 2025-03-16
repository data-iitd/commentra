package main

import (
	"fmt"
)

func main() {
	const MAX_V = 999999
	var prime [MAX_V + 1]bool
	var i, k, n int
	for i = 2; i <= MAX_V; i++ {
		prime[i] = true
	}
	for i = 2; i*i <= MAX_V; i++ {
		if prime[i] {
			for k = 2 * i; k <= MAX_V; k += i {
				prime[k] = false
			}
		}
	}
	prime[0] = false
	prime[1] = false
	count := 0
	for {
		fmt.Scan(&n)
		count++
		cnt := 0
		for i = n; i > 0; i-- {
			if prime[i] {
				cnt++
			}
		}
		fmt.Println(cnt)
		if count == 30 {
			break
		}
	}
}

