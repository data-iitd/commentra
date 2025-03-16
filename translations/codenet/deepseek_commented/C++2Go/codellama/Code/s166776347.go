
package main

import (
	"fmt"
)

func main() {
	// 入力
	var N, K int
	fmt.Scan(&N, &K)
	A := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
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
			ans1 %= 1000000007
		}
	}

	// Count the frequency of each element in the array A
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

	// Calculate the final answer
	tmp := K * (K - 1)
	tmp /= 2
	tmp %= 1000000007
	tmp *= ans2
	tmp %= 1000000007
	ans := 0
	ans += ans1 * K
	ans %= 1000000007
	ans += tmp
	ans %= 1000000007

	// Output the final answer
	fmt.Println(ans)
}

