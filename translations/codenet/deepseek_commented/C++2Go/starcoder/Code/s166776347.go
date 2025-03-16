<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"math"
)

// <START-OF-CODE>

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
<<<<<<< HEAD
	tmp := K * (K - 1)
=======
	tmp := K*(K-1)
>>>>>>> 98c87cb78a (data updated)
	tmp /= 2
	tmp %= int(math.Pow10(9) + 7)
	tmp *= ans2
	tmp %= int(math.Pow10(9) + 7)
	ans := 0
	ans += ans1 * K
	ans %= int(math.Pow10(9) + 7)
	ans += tmp
	ans %= int(math.Pow10(9) + 7)

	// Output the final answer
	fmt.Printf("%d\n", ans)
}

// 