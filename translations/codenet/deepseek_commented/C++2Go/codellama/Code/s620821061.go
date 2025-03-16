package main

import (
	"fmt"
	"math"
)

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func main() {
	for {
		var n, m int
		fmt.Scan(&n, &m)
		if n == 0 {
			break
		}
		a := make([]int, n)
		b := make([]int, m)
		for i := 0; i < n; i++ {
			fmt.Scan(&a[i])
		}
		for i := 0; i < m; i++ {
			fmt.Scan(&b[i])
		}

		match := make([]int, n+m)
		for i := 0; i < n; i++ {
			for j := 0; j < m; j++ {
				if gcd(a[i], b[j]) != 1 {
					match[i] = j + n
					match[j+n] = i
				}
			}
		}

		res := 0
		for i := 0; i < n; i++ {
			if match[i] < 0 {
				continue
			}
			for j := 0; j < m; j++ {
				if match[j+n] < 0 {
					continue
				}
				if gcd(a[i], b[j]) != 1 {
					continue
				}
				if match[i] == j+n && match[j+n] == i {
					res++
				}
			}
		}
		fmt.Println(res)
	}
}

