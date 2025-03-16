package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)

	cnt := make([][]int64, 10)
	for i := range cnt {
		cnt[i] = make([]int64, 10)
	}

	for i := 1; i <= n; i++ {
		b := i % 10
		a := i
		for a >= 10 {
			a /= 10
		}
		cnt[a][b]++
	}

	var ans int64 = 0
	for i := 1; i <= 9; i++ {
		for j := 1; j <= 9; j++ {
			ans += cnt[i][j] * cnt[j][i]
		}
	}

	fmt.Println(ans)
}

// <END-OF-CODE>
