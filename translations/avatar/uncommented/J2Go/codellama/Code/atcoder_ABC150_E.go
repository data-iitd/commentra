
package main

import (
	"bufio"
	"fmt"
	"os"
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
	if n == 1 {
		fmt.Println(c[0] * 2 % 1000000007)
		return
	}
	Arrays.parallelSort(c)
	b := power(2, n)
	a := power(2, n-2)
	ans := 0
	for i := 2; i <= n+1; i++ {
		val := a * i % 1000000007
		val *= c[n+1-i]
		val %= 1000000007
		ans += val
		ans %= 1000000007
	}
	ans *= b
	ans %= 1000000007
	fmt.Println(ans)
}

func power(x, n int) int {
	if n == 0 {
		return 1
	}
	val := power(x, n/2)
	val = val * val % 1000000007
	if n%2 == 1 {
		val = val * x % 1000000007
	}
	return val
}

