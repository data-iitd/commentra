package main

import "fmt"

func main() {
	var N int
	fmt.Scan(&N)
	n := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&n[i])
	}
	a := 1
	pos := 0
	for i := 1; i < N; i++ {
		if n[pos] > n[i] {
			a += 1
			pos = i
		}
	}
	fmt.Println(a)
}

