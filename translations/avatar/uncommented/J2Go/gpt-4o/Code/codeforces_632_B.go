package main

import (
	"fmt"
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

	sum := int64(0)
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
		if sum1 > ans {
			ans = sum1
		}
	}

	sum1 = sum
	for i := len(s) - 1; i >= 0; i-- {
		if s[i] == 'A' {
			sum1 += int64(a[i])
		} else {
			sum1 -= int64(a[i])
		}
		if sum1 > ans {
			ans = sum1
		}
	}

	fmt.Println(ans)
}

// <END-OF-CODE>
