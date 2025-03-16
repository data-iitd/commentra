package main

import (
	"fmt"
	"sort"
)

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func lcm(a, b int) int {
	return a * b / gcd(a, b)
}

func main() {
	var n, k, q int
	fmt.Scanf("%d%d%d", &n, &k, &q)

	// 初期化
	point := make([]int, n)
	for i := 0; i < n; i++ {
		point[i] = k
	}

	// 問題ずつそれぞれのポイントを考える
	for i := 0; i < q; i++ {
		var a int
		fmt.Scanf("%d", &a)
		point[a-1]++
	}

	// 求め方を変えた
	for i := 0; i < n; i++ {
		if k-(q-point[i]) > 0 {
			fmt.Println("Yes")
		} else {
			fmt.Println("No")
		}
	}
}

