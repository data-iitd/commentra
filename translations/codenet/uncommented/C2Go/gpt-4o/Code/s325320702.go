package main

import (
	"fmt"
)

func main() {
	var l, r, d int64
	var ans int64 = 0

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

// <END-OF-CODE>
