package main

import (
	"fmt"
	"math"
)

func main() {
	const MAX_V = 999999
	prime := make([]int, MAX_V+1)
	for i := 2; i <= MAX_V; i++ {
		prime[i] = 1
	}
	for i := 2; i*i <= MAX_V; i++ {
		if prime[i] == 1 {
			for k := 2 * i; k <= MAX_V; k += i {
				prime[k] = 0
			}
		}
	}
	prime[0] = 0
	prime[1] = 0
	count := 0
	for {
		var n int
		fmt.Scanf("%d", &n)
		if n == 0 {
			break
		}
		count++
		cnt := 0
		for i := n; i > 0; i-- {
			if prime[i] == 1 {
				cnt++
			}
		}
		fmt.Printf("%d\n", cnt)
		if count == 30 {
			break
		}
	}
}

