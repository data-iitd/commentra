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

func pow(base, exp, mod int) int {
	result := 1
	base = base % mod
	for exp > 0 {
		if exp%2 == 1 {
			result = (result * base) % mod
		}
		exp = exp >> 1
		base = (base * base) % mod
	}
	return result
}

// <END-OF-CODE>
