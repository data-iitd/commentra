package main

import "fmt"

func main() {
	var n, m int
	fmt.Scan(&n, &m)
	b := make([]int, n*2)
	b[0] = b[n-1] = b[n] = b[2*n-1] = 0
	for i := 0; i < m; i++ {
		var r, c int
		fmt.Scan(&r, &c)
		b[r-1] = b[n+c-1] = 0
	}
	if n%2 == 1 && b[n/2] == 1 && b[n+n/2] == 1 {
		b[n/2] = 0
	}
	fmt.Println(sum(b))
}

func sum(b []int) int {
	var s int
	for _, v := range b {
		s += v
	}
	return s
}

