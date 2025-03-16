package main

import (
	"fmt"
)

func main() {
	var n int
	var a, b, c string
	fmt.Scan(&n)
	fmt.Scan(&a, &b, &c)

	ans := 0

	for i := 0; i < n; i++ {
		if a[i] == b[i] && b[i] == c[i] {
			// Do nothing
		} else if a[i] == b[i] || b[i] == c[i] || a[i] == c[i] {
			ans++
		} else {
			ans += 2
		}
	}
	fmt.Println(ans)
}

