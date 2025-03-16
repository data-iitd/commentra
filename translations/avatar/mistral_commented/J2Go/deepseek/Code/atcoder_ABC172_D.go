package main

import (
	"fmt"
)

func main() {
	var n int
	var ans int64 = 0

	fmt.Scan(&n)

	for i := 1; i < n+1; i++ {
		ans += int64(i) * int64(n/i) * (int64(n/i) + 1) / 2
	}

	fmt.Println(ans)
}

