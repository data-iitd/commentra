package main

import (
	"fmt"
	"sort"
)

func main() {
	const mod = 1000000007
	var n int
	fmt.Scan(&n)
	c := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&c[i])
	}
	sort.Sort(sort.Reverse(sort.IntSlice(c)))

	b := pow(2, 2*n-2, mod)
	a := (2 * b) % mod
	ans := 0

	for i := 0; i < n; i++ {
		ans = (ans + c[i]*(a+i*b)) % mod
	}
	fmt.Println(ans)
}

func pow(x, y, p int) int {
	res := 1
	x = x % p
	for y > 0 {
		if y&1 == 1 {
			res = (res * x) % p
		}
		y = y >> 1
		x = (x * x) % p
	}
	return res
}

// <END-OF-CODE>
