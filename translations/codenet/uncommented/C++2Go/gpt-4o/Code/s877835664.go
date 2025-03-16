package main

import (
	"fmt"
	"math"
)

func main() {
	var N, K int64
	fmt.Scan(&N, &K)

	A := make([]int64, N+1)
	for i := int64(1); i <= N; i++ {
		fmt.Scan(&A[i])
	}

	cur := int64(1)
	dic := make([]int64, N+1)
	for i := range dic {
		dic[i] = -1
	}
	flg := false

	for i := int64(1); i <= K; i++ {
		if dic[cur] < 0 || flg {
			dic[cur] = i
			cur = A[cur]
		} else if !flg {
			tmp := K - (dic[cur] - 1)
			tmp %= (i - dic[cur])
			i = K - tmp
			flg = true
		}
	}

	fmt.Println(cur)
}

// <END-OF-CODE>
