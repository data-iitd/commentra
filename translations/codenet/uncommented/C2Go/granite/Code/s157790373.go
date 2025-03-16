
package main

import (
	"bufio"
	"fmt"
	"os"
)

const (
	LEN  = 300
	TRUE = 1
	FALSE = -1
)

var (
	n, q, M int
	A [LEN]int
	flag int
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	fmt.Fscanf(reader, "%d\n", &n)
	for i := 0; i < n; i++ {
		fmt.Fscanf(reader, "%d\n", &A[i])
	}

	fmt.Fscanf(reader, "%d\n", &q)
	for i := 0; i < q; i++ {
		fmt.Fscanf(reader, "%d\n", &M)
		flag = FALSE

		solve(-1, M)
		if flag == TRUE {
			fmt.Println("yes")
		} else {
			fmt.Println("no")
		}
	}
}

func solve(i, m int) {
	if i > n {
		return
	} else if m < 0 {
		return
	} else if m == 0 || m-A[i+1] == 0 {
		flag = TRUE
		return
	} else {
		//not use A[i]
		solve(i+1, m)
		//use A[i]
		solve(i+1, m-A[i])
	}
}

