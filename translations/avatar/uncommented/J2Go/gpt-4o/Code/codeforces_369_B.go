package main

import (
	"fmt"
)

func main() {
	var n, k, l, r, sAll, sk int
	fmt.Scan(&n, &k, &l, &r, &sAll, &sk)
	ans := getPoints(n, k, l, r, sAll, sk)
	for _, num := range ans {
		fmt.Print(num, " ")
	}
}

func getPoints(n, k, l, r, sAll, sk int) []int {
	ans := make([]int, n)
	for i := range ans {
		ans[i] = l
	}
	sAll -= sk + (n-k)*l
	sk -= k * l

	for sk > 0 {
		idx := n - 1
		for sk > 0 && idx >= n-k {
			ans[idx]++
			sk--
			idx--
		}
	}

	for sAll > 0 {
		idx := 0
		for sAll > 0 && idx < n-k {
			ans[idx]++
			sAll--
			idx++
		}
	}

	return ans
}

// <END-OF-CODE>
