
package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)
	a := make([]int, n)
	acc := make([]int, n+1)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
		acc[i+1] = acc[i] + a[i]
		acc[i+1] %= 1000000007
	}

	ans := 0
	for i := 0; i < n; i++ {
		ans += a[i] % 1000000007 * (1000000007 + acc[n] - acc[i+1]) % 1000000007
		ans %= 1000000007
	}
	fmt.Println(ans)
}

