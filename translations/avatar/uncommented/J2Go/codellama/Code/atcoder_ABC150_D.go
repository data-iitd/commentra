
package main

import (
	"fmt"
	"strconv"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
		a[i] = a[i] / 2
	}
	var gcd, lcd int64 = 1, 1
	for i := 0; i < n; i++ {
		gcd = getGCD(lcd, int64(a[i]))
		lcd = lcd * int64(a[i]) / gcd
		if lcd > int64(m) {
			fmt.Println(0)
			return
		}
	}
	for i := 0; i < n; i++ {
		if (lcd/int64(a[i]))%2 == 0 {
			fmt.Println(0)
			return
		}
	}
	fmt.Println(int(m/lcd + 1) / 2)
}

func getGCD(a, b int64) int64 {
	if b == 0 {
		return a
	} else {
		return getGCD(b, a%b)
	}
}

