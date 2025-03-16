package main

import (
	"fmt"
)

func main() {
	var r, g, b, n int
	fmt.Scan(&r, &g, &b, &n)

	ans := 0

	for i := 0; i <= n/r; i++ {
		for j := 0; j <= n/g; j++ {
			num := n - r*i - g*j
			if num >= 0 && num%b == 0 {
				ans++
			}
		}
	}

	fmt.Println(ans)
}

