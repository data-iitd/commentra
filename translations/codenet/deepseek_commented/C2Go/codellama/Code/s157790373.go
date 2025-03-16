package main

import "fmt"

const (
	LEN = 300
	TRUE = 1
	FALSE = -1
)

var (
	n int
	A [LEN]int
	flag int
)

func solve(i, m int) int {
	if i > n {
		return FALSE
	}
	if m < 0 {
		return FALSE
	}
	if m == 0 || m - A[i+1] == 0 {
		flag = TRUE
		return TRUE
	}
	solve(i+1, m)
	solve(i+1, m-A[i])
}

func main() {
	var q, M int
	var i, j, k int

	fmt.Scan(&n)
	for i = 0; i < n; i++ {
		fmt.Scan(&A[i])
	}
	fmt.Scan(&q)
	for i = 0; i < q; i++ {
		fmt.Scan(&M)
		flag = FALSE
		solve(-1, M)
		if flag == TRUE {
			fmt.Println("yes")
		} else {
			fmt.Println("no")
		}
	}
}

