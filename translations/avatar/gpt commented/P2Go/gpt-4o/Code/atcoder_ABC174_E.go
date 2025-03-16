package main

import (
	"fmt"
)

func check(lis []int, k int, mid int) bool {
	for _, i := range lis {
		if i%mid == 0 {
			k++
		}
		k -= (i / mid)
	}
	return k >= 0
}

func main() {
	var n, k int
	fmt.Scan(&n, &k)
	lis := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&lis[i])
	}

	a, b := 1, lis[0]
	for _, value := range lis {
		if value > b {
			b = value
		}
	}

	ans := b

	for a <= b {
		mid := (a + b) / 2
		if check(lis, k, mid) {
			ans = mid
			b = mid - 1
		} else {
			a = mid + 1
		}
	}

	fmt.Println(ans)
}

// <END-OF-CODE>
