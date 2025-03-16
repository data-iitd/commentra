package main

import (
	"fmt"
)

func gcd(a, b int) int {
	if a < b {
		a, b = b, a
	}
	var r int
	for (r = a % b) > 0 {
		a, b = b, r
	}
	return b
}

func main() {
	var n int
	fmt.Scan(&n)

	var ans int
	fmt.Scan(&ans)

	for i := 1; i < n; i++ {
		var a int
		fmt.Scan(&a)
		ans = gcd(ans, a)
	}

	fmt.Println(ans)
}

// <END-OF-CODE>
