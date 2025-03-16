package main

import (
	"fmt"
)

func main() {
	var n, ii, a, b int
	fmt.Scan(&n)
	cnt := [10][10]int{}
	for i := 0; i < 100; i++ {
		cnt[i%10][i/10] = 0
	}
	for i := 1; i <= n; i++ {
		b = i % 10
		a = i
		for a >= 10 {
			a /= 10
		}
		cnt[a][b]++
	}
	var ans int64
	ans = 0
	for i := 1; i <= 9; i++ {
		for j := 1; j <= 9; j++ {
			ans += int64(cnt[i][j]) * int64(cnt[j][i])
		}
	}
	fmt.Println(ans)
}
