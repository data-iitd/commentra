
package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	var n int
	fmt.Scan(&n)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	var s string
	fmt.Scan(&s)
	var sum int64
	for i := 0; i < len(s); i++ {
		if s[i] == 'B' {
			sum += int64(a[i])
		}
	}
	ans := sum
	sum1 := sum
	for i := 0; i < len(s); i++ {
		if s[i] == 'A' {
			sum1 += int64(a[i])
		} else {
			sum1 -= int64(a[i])
		}
		ans = max(ans, sum1)
	}
	sum1 = sum
	for i := len(s) - 1; i >= 0; i-- {
		if s[i] == 'A' {
			sum1 += int64(a[i])
		} else {
			sum1 -= int64(a[i])
		}
		ans = max(ans, sum1)
	}
	fmt.Println(ans)
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

