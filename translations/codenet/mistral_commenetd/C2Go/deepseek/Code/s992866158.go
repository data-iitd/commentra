package main

import (
	"fmt"
)

func main() {
	var n, k, cnt int
	fmt.Scan(&n, &k)
	cnt = 0
	for i := 0; i < n; i++ {
		var h int
		fmt.Scan(&h)
		if h >= k {
			cnt++
		}
	}
	fmt.Println(cnt)
}

