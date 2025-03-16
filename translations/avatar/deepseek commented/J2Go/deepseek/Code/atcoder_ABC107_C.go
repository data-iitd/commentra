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
	
	var temp, ans int
	ans = 1000000000
	
	if K == 1 {
		for i := 0; i < N; i++ {
			temp = S[i]
			if temp < 0 {
				temp = -temp
			}
			if temp < ans {
				ans = temp
			}
		}
		fmt.Println(ans)
	} else if N - K != 0 {
		for i := 0; i <= N - K; i++ {
			min := S[i]
			max := S[i + K - 1]
			
			if min < 0 && max > 0 {
				temp = minMin(2 * (-min) + max, (-min) + 2 * max)
			} else {
				if min < 0 {
					min = -min
				}
				if max < 0 {
					max = -max
				}
				if min > max {
					temp = min
				} else {
					temp = max
				}
			}
			
			if temp < ans {
				ans = temp
			}
		}
		fmt.Println(ans)
	} else {
		min := S[0]
		max := S[N - 1]
		
		if min < 0 && max > 0 {
			fmt.Println(minMin(2 * (-min) + max, (-min) + 2 * max))
		} else {
			if min < 0 {
				min = -min
			}
			if max < 0 {
				max = -max
			}
			if min > max {
				fmt.Println(min)
			} else {
				fmt.Println(max)
			}
		}
	}
}

func minMin(a, b int) int {
	if a < b {
		return a
	}
	return b
}
