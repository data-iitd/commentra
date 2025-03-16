package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)
	ans := 0
	for i := 1; i < n+1; i++ {
		ans += int(int64(i) * int64(n/i) * int64(n/i+1) / 2)
	}
	fmt.Println(ans)
}

