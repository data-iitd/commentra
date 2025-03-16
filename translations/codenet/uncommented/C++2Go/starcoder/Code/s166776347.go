package main

import (
	"fmt"
	"math"
)

func main() {
	// 入力
	var N, K int
	fmt.Scanf("%d %d\n", &N, &K)
	A := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scanf("%d\n", &A[i])
	}

	// 解法
	ans1 := 0
	for i := 0; i < N; i++ {
		for j := 0; j < N; j++ {
			if i >= j {
				continue
			}
			if A[i] > A[j] {
				ans1++
			}
			ans1 %= int(math.Pow10(9) + 7)
		}
	}

	count := make([]int, 2005)
	for i := 0; i < N; i++ {
		count[A[i]-1]++
	}
	ans2 := 0
	remain := N
	for i := 0; i < 2005; i++ {
		remain -= count[i]
		ans2 += count[i] * remain
	}
	ans2 %= int(math.Pow10(9) + 7)
	ans := 0
	tmp := K*(K-1)
	tmp /= 2
	tmp %= int(math.Pow10(9) + 7)
	tmp *= ans2
	tmp %= int(math.Pow10(9) + 7)
	ans += ans1 * K
	ans %= int(math.Pow10(9) + 7)
	ans += tmp
	ans %= int(math.Pow10(9) + 7)
	// 出力
	fmt.Println(ans)
}

