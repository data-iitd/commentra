package main

import (
	"fmt"
)

func main() {
	var l, r, d int
	var ans int

	fmt.Scan(&l)
	fmt.Scan(&r)
	fmt.Scan(&d)

	for i := l; i <= r; i++ {
		if i%d == 0 {
			ans++
		}
	}

	fmt.Println(ans)
}

