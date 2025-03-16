package main

import "fmt"

func main() {
	var A, B int
	fmt.Scanf("%d %d", &A, &B)
	if A < 10 && B < 10 {
		fmt.Printf("%d\n", A*B)
	} else {
		fmt.Printf("-1\n")
	}
}

