package main

import (
	"fmt"
)

func main() {
	var A, B int
	fmt.Scan(&A, &B)

	ans := 0
	out := 1

	for out < B {
		out--
		out += A
		ans++
	}
	fmt.Println(ans)
}

