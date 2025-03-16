package main

import (
	"fmt"
)

func main() {
	var N, K int64
	A := make([]int64, 200100)
	B := make([]int64, 200100)
	for i := range B {
		B[i] = -1
	}
	now := int64(1)
	var cnt int64 = 0

	fmt.Scan(&N, &K)
	for i := int64(1); i <= N; i++ {
		fmt.Scan(&A[i])
	}

	B[1] = 0
	var j int64
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
		for j := int64(0); j < tmp; j++ {
			now = A[now]
		}
	}
	fmt.Println(now)
}

// <END-OF-CODE>
