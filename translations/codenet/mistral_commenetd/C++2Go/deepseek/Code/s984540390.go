package main

import (
	"fmt"
)

func main() {
	var h int64
	fmt.Scan(&h)

	var ans, cnt int64 = 0, 1

	for h != 1 {
		if h%2 != 0 {
			h--
		}
		h /= 2
		cnt *= 2
		ans += cnt
	}

	fmt.Println(ans + 1)
}

