package main

import (
	"fmt"
)

func main() {
	var h int
	fmt.Scan(&h)
	ans, cnt := 0, 1
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

