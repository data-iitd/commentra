package main

import (
	"fmt"
)

func main() {
	var N, K int
	fmt.Scan(&N, &K)

	S := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&S[i])
	}

	var temp, ans int = 0, 1000000000

	if K == 1 {
		for i := 0; i < N; i++ {
			temp = S[i]
			if ans > abs(temp) {
				ans = abs(temp)
			}
		}
		fmt.Println(ans)
	} else if N-K != 0 {
		for i := 0; i <= N-K; i++ {
			min, max := S[i], S[i+K-1]
			if min < 0 && max > 0 {
				temp = 2*abs(min) + max
			} else {
				temp = maxInt(abs(min), abs(max))
			}
			if ans > temp {
				ans = temp
			}
		}
		fmt.Println(ans)
	} else {
		min, max := S[0], S[N-1]
		if min < 0 && max > 0 {
			fmt.Println(minInt(2*abs(min)+max, abs(min)+2*abs(max)))
		} else {
			fmt.Println(maxInt(abs(min), abs(max)))
		}
	}
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func maxInt(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func minInt(a, b int) int {
	if a < b {
		return a
	}
	return b
}

