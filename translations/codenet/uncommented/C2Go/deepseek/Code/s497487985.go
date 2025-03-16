package main

import (
	"fmt"
)

// 公約数
func gcd(a, b int) int {
	if b == 0 {
		return a
	} else {
		return gcd(b, a % b)
	}
}

// 最小公倍数 = a * b / 最大公約数
func lcm(a, b int) int {
	return a * b / gcd(a, b)
}

func main() {
	var n, k, q int
	var a []int
	var point []int

	fmt.Scan(&n, &k, &q)

	// 初期化
	point = make([]int, n)
	for i := 0; i < n; i++ {
		point[i] = k
	}

	for i := 0; i < q; i++ {
		fmt.Scan(&a[i])
		point[a[i]-1]++
		for j := 0; j < n; j++ {
			if a[i] != (j+1) && point[j] < k {
				point[j]++
			}
		}
	}

	for i := 0; i < n; i++ {
		if point[i] > q {
			fmt.Println("Yes")
		} else {
			fmt.Println("No")
		}
	}
}
