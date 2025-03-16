package main

import (
	"fmt"
)

func gcd(a int, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func ruisekiLR(array []int) ([]int, []int) {
	n := len(array)
	left := make([]int, n+1)
	right := make([]int, n+1)

	for i := 0; i < n; i++ {
		left[i+1] = gcd(left[i], array[i])
	}
	for i := n - 1; i >= 0; i-- {
		right[i] = gcd(right[i+1], array[i])
	}
	return left, right
}

func main() {
	var n int
	fmt.Scan(&n)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	left, right := ruisekiLR(a)
	ans := 0
	for i := 0; i < n; i++ {
		ans = max(gcd(left[i], right[i+1]), ans)
	}
	fmt.Println(ans)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// <END-OF-CODE>
