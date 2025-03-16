package main

import (
	"fmt"
	"math"
)

func main() {
	var N, K int
	fmt.Scan(&N, &K)
	S := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&S[i])
	}

	ans := math.MaxInt64
	if K == 1 {
		for i := 0; i < N; i++ {
			temp := S[i]
			ans = int(math.Min(float64(math.Abs(float64(temp))), float64(ans)))
		}
		fmt.Println(ans)
	} else if N-K != 0 {
		for i := 0; i <= N-K; i++ {
			min := S[i]
			max := S[i+K-1]
			if min < 0 && max > 0 {
				temp := int(math.Min(float64(2*(-min)+max), float64(-min+2*max)))
				ans = int(math.Min(float64(ans), float64(temp)))
			} else {
				temp := int(math.Max(math.Abs(float64(min)), math.Abs(float64(max))))
				ans = int(math.Min(float64(ans), float64(temp)))
			}
		}
		fmt.Println(ans)
	} else {
		min := S[0]
		max := S[N-1]
		if min < 0 && max > 0 {
			fmt.Println(int(math.Min(float64(2*(-min)+max), float64(-min+2*max))))
		} else {
			fmt.Println(int(math.Max(math.Abs(float64(min)), math.Abs(float64(max)))))
		}
	}
}

