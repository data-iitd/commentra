package main

import (
	"fmt"
	"sort"
)

func main() {
	var n int
	fmt.Scan(&n)

	ans := make([]int64, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&ans[i])
	}

	sort.Slice(ans, func(i, j int) bool {
		return ans[i] < ans[j]
	})

	var count int64 = ans[n-1]

	for i := n - 2; i >= 0; i-- {
		if ans[i] < ans[i+1] {
			count += ans[i]
		} else {
			for ans[i] >= ans[i+1] {
				ans[i]--
			}
			if ans[i] > 0 {
				count += ans[i]
			}
		}
	}

	fmt.Println(count)
}
