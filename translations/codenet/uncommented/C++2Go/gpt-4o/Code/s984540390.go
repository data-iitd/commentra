package main

import (
	"fmt"
)

func main() {
	var h, ans, cnt int64 = 0, 0, 1
	fmt.Scan(&h)

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

// <END-OF-CODE>
