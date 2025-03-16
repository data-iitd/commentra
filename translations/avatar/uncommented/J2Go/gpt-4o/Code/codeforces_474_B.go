package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)
	arr := make([]int, n)
	fmt.Scan(&arr[0])
	for i := 1; i < n; i++ {
		var x int
		fmt.Scan(&x)
		arr[i] = x + arr[i-1]
	}
	var m int
	fmt.Scan(&m)
	q := make([]int, m)
	for i := 0; i < m; i++ {
		fmt.Scan(&q[i])
	}
	for k := 0; k < m; k++ {
		fmt.Println(fun(arr, q[k], n, m) + 1)
	}
}

func fun(arr []int, q, n, m int) int {
	res := 0
	i, j := 0, n
	for i <= j {
		md := i + (j-i)/2
		if arr[md] == q {
			return md
		} else if arr[md] > q {
			res = md
			j = md - 1
		} else {
			i = md + 1
		}
	}
	return res
}

// <END-OF-CODE>
