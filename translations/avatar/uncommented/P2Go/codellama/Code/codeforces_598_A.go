package main

import "fmt"

func solve(n int) int {
	s := (1 + n) * n / 2
	t := 1
	for t <= n {
		s -= 2 * t
		t *= 2
	}
	return s
}

func main() {
	var t int
	fmt.Scan(&t)
	for i := 0; i < t; i++ {
		var n int
		fmt.Scan(&n)
		fmt.Println(solve(n))
	}
}

