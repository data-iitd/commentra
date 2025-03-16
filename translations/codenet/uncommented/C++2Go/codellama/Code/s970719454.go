package main

import (
	"fmt"
)

func main() {
	for {
		var n, m int
		fmt.Scan(&n, &m)
		if n == 0 {
			break
		}

		here := make([]int, 100001)
		dp1 := make([]int, 100001)
		dp2 := make([]int, 100001)

		for i := 0; i < 100001; i++ {
			here[i] = dp1[i] = dp2[i] = 0
		}

		dpflg := false

		for i := 0; i < m; i++ {
			var a int
			fmt.Scan(&a)
			if a == 0 {
				dpflg = true
			}

			here[a] = 1
		}

		maxi1 := 0
		maxi2 := 0

		for i := 1; i <= n; i++ {
			if here[i] == 1 {
				dp1[i] = dp1[i-1] + 1
			}
			maxi1 = max(dp1[i], maxi1)
		}

		for i := 1; i <= n; i++ {
			if here[i] == 1 {
				dp2[i] = dp2[i-1] + 1
			} else {
				dp2[i] = dp1[i-1] + 1
			}
			maxi2 = max(dp2[i], maxi2)
		}

		if !dpflg {
			fmt.Println(maxi1)
		} else {
			fmt.Println(maxi2)
		}
	}
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

