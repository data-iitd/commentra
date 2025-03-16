package main

import "fmt"

const MAX_V = 999999

func main() {
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
	var count int
	for {
		var n int
		_, err := fmt.Scan(&n)
		if err != nil {
			break
		}
		count++
		var cnt int
		for i := n; i > 0; i-- {
			if prime[i] == 1 {
				cnt++
			}
		}
		fmt.Println(cnt)
		if count == 30 {
			break
		}
	}
}

