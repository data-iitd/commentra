package main

import (
	"fmt"
)

func main() {
	var H, W int64
	fmt.Scan(&H, &W)

	var ans int64
	if H == 1 || W == 1 {
		ans = 1
	} else {
		m := H * W
		if m%2 == 0 {
			ans = m / 2
		} else {
			ans = m/2 + 1
		}
	}
	fmt.Println(ans)
}

