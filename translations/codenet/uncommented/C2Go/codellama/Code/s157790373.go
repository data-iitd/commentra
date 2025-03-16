package main

import "fmt"

func solve(i, m int) bool {
	if i > n {
		return false
	} else if m < 0 {
		return false
	} else if m == 0 || m-A[i+1] == 0 {
		flag = true
		return true
	} else {
		//not use A[i]
		solve(i+1, m)
		//use A[i]
		solve(i+1, m-A[i])
	}
}

func main() {
	var n, q, M int
	var A [LEN]int
	var flag bool

	fmt.Scanf("%d", &n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &A[i])
	}

	fmt.Scanf("%d", &q)
	for i := 0; i < q; i++ {
		fmt.Scanf("%d", &M)
		flag = false

		solve(-1, M)
		if flag == true {
			fmt.Println("yes")
		} else {
			fmt.Println("no")
		}
	}
}

