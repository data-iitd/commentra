
package main

import (
	"fmt"
	"math"
	"strconv"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n)
	c := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&c[i])
	}
	c = sort(c)
	b := pow(2, 2*n-2, 1000000007)
	a := 2 * b % 1000000007
	ans := 0
	for i := 0; i < n; i++ {
		ans += c[i] * (a + i*b)
		ans %= 1000000007
	}
	fmt.Println(ans)
}

func sort(c []int) []int {
	for i := 0; i < len(c)-1; i++ {
		for j := i + 1; j < len(c); j++ {
			if c[i] < c[j] {
				c[i], c[j] = c[j], c[i]
			}
		}
	}
	return c
}

func pow(base, exponent, mod int) int {
	result := 1
	for exponent > 0 {
		if exponent%2 == 1 {
			result = (result * base) % mod
		}
		base = (base * base) % mod
		exponent /= 2
	}
	return result
}

