package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)
	for i := 0; i < n; i++ {
		solve()
	}
}

func solve() {
	var n int
	fmt.Scan(&n)
	fmt.Println(!n)
}

