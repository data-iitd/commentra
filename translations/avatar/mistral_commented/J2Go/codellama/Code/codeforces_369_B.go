
package main

import (
	"fmt"
	"math"
)

func main() {
	var n, k, l, r, sAll, sk int
	fmt.Scan(&n, &k, &l, &r, &sAll, &sk)

	ans := make([]int, n)
	for i := 0; i < n; i++ {
		ans[i] = l
	}

	sAll -= sk + (n - k) * l
	sk -= k * l

	idx := n - 1
	for sk > 0 && idx >= n-k {
		ans[idx]++
		sk--
		idx--
	}

	for sAll > 0 {
		idx = 0
		for sAll > 0 && idx < n-k {
			ans[idx]++
			sAll--
			idx++
		}
	}

	for _, num := range ans {
		fmt.Print(num, " ")
	}
	fmt.Println()
}

