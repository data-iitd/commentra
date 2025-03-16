
package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	var n, b int
	var ans []int64
	var q []int64

	fmt.Scan(&n, &b)
	ans = make([]int64, n)
	q = make([]int64, 0)

	for i := 0; i < n; i++ {
		var t, d int
		fmt.Scan(&t, &d)

		for len(q) > 0 && q[0] <= int64(t) {
			q = q[1:]
		}

		if len(q) <= b {
			ans[i] = q[len(q)-1] + int64(d)
			q = append(q, ans[i])
		} else {
			ans[i] = -1
		}
	}

	for i := 0; i < n; i++ {
		fmt.Printf("%d ", ans[i])
	}
	fmt.Println()
}

