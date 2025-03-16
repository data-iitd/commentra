package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)

	l := 1
	r := n

	for l < r {
		mid := l + (r-l)/2
		idxcnt := float64(mid) * (float64(mid) + 1) / 2
		if idxcnt < float64(n) {
			l = mid + 1
		} else {
			r = mid
		}
	}

	l -= 1
	idxcnt := float64(l) * (float64(l) + 1) / 2

	fmt.Println(int(n - idxcnt))
}

