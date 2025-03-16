package main

import (
	"fmt"
)

func main() {
	var N, K int
	var A [200100]int
	var B [200100]int = [-1]int{-1}
	var now int = 1
	var cnt int = 0
	fmt.Scan(&N, &K)
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i+1])
	}
	for i := 0; i < 200100; i++ {
		B[i] = -1
	}
	//途中でどっかに合流したら抜ける
	var j int
	B[1] = 0
	for j = 1; j <= K; j++ {
		now = A[now]
		if B[now] == -1 {
			B[now] = j
		} else {
			cnt = j
			break
		}
	}
	if j < K {
		tmp := (K - B[now]) % (cnt - B[now])
		for j := 0; j < tmp; j++ {
			now = A[now]
		}
	}
	fmt.Println(now)
}
