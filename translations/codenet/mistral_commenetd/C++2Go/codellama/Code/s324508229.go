
package main

import (
	"fmt"
)

func main() {
	var n, ii, a, b int
	fmt.Scan(&n)
	cnt := make([][]int, 10)
	for i := 0; i < 10; i++ {
		cnt[i] = make([]int, 10)
	}
	for i := 1; i <= n; i++ {
		b = i % 10
		a = i
		for a >= 10 {
			a /= 10
		}
		cnt[a][b]++
	}
	ans := 0
	for i := 1; i <= 9; i++ {
		for j := 1; j <= 9; j++ {
			ans += cnt[i][j] * cnt[j][i]
		}
	}
	fmt.Println(ans)
}

