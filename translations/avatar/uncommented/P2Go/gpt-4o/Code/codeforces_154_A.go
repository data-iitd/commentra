package main

import (
	"fmt"
)

func main() {
	var s string
	fmt.Scan(&s)
	var n int
	fmt.Scan(&n)
	ans := 0

	for i := 0; i < n; i++ {
		var x string
		fmt.Scan(&x)
		a, b := 0, 0

		for _, j := range s {
			if j == rune(x[0]) {
				a++
			} else if j == rune(x[1]) {
				b++
			} else {
				ans += min(a, b)
				a, b = 0, 0
			}
		}
		ans += min(a, b)
	}
	fmt.Println(ans)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// <END-OF-CODE>
