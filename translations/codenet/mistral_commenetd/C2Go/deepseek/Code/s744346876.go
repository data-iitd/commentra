package main

import (
	"fmt"
)

func main() {
	var A, B int
	fmt.Scan(&A, &B)
	if A < 10 && B < 10 {
		fmt.Println(A * B)
	} else {
		fmt.Println(-1)
	}
}

