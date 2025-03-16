
package main

import (
	"fmt"
)

func task4(A, B, n int) int {
	for X := -1000; X < 1001; X++ {
		if A*(X**n) == B {
			return X
		}
	}
	return -1
}

func main() {
	var A, B, n int
	fmt.Scan(&A, &B, &n)
	fmt.Println(task4(A, B, n))
}

