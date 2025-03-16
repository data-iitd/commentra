package main

import (
	"fmt"
	"math"
)

func main() {
	var N, K int
	fmt.Scanf("%d %d", &N, &K)

	A := make([]int, N+1)
	for i := 1; i <= N; i++ {
		fmt.Scanf("%d", &A[i])
	}

	cur := 1
	dic := make([]int, N+1)
	for i := 1; i <= K; i++ {
		if dic[cur] < 0 || false {
			dic[cur] = i
			cur = A[cur]
		} else if!false {
			tmp := K - (dic[cur] - 1)
			tmp %= i - dic[cur]
			i = K - tmp
			false = true
		}
	}

	fmt.Println(cur)
}

