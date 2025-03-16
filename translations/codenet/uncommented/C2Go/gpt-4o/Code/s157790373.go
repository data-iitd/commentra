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

func solve(i int, m int) int {
	if i >= n {
		return FALSE
	} else if m < 0 {
		return FALSE
	} else if m == 0 || m-A[i+1] == 0 {
		flag = TRUE
		return TRUE
	} else {
		// not use A[i]
		solve(i+1, m)
		// use A[i]
		solve(i+1, m-A[i])
	}
	return FALSE
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

		solve(-1, M)
		if flag == TRUE {
			fmt.Println("yes")
		} else {
			fmt.Println("no")
		}
	}
}

// <END-OF-CODE>
