package main

import (
	"fmt"
)

func main() {
	var n, k int
	var l, r int64 = 0, 0

	fmt.Scan(&n, &k)

	if k%2 == 0 {
		for i := 1; i <= n; i++ {
			if i%k == k/2 {
				l++
			} else if i%k == 0 {
				r++
			}
		}
		fmt.Println(l*l*l + r*r*r)
	} else {
		for i := 1; i <= n; i++ {
			if i%k == 0 {
				r++
			}
		}
		fmt.Println(r*r*r)
	}
}
