package main

import (
	"fmt"
)

const LEN = 300
const TRUE = 1
const FALSE = -1

var n int
var A [LEN]int
var flag int

func solve(i, m int) int {
	if i > n {
		return FALSE
	}
	if m < 0 {
		return FALSE
	}
	if m == 0 || m-A[i] == 0 {
		flag = TRUE
		return TRUE
	}
	solve(i+1, m)
	solve(i+1, m-A[i])
	return 0
}

func main() {
	var q, M int
	fmt.Scan(&n)
	for i := 0; i < n; i++ {
		fmt.Scan(&A[i])
	}
	fmt.Scan(&q)
	for i := 0; i < q; i++ {
		fmt.Scan(&M)
		flag = FALSE
		solve(0, M)
		if flag == TRUE {
			fmt.Println("yes")
		} else {
			fmt.Println("no")
		}
	}
}

