package main

import (
	"fmt"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		var temp int
		fmt.Scan(&temp)
		a[i] = temp / 2
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

	fmt.Println((m/int(lcd)+1)/2)
}

func getGCD(a, b int64) int64 {
	if b == 0 {
		return a
	}
	return getGCD(b, a%b)
}
