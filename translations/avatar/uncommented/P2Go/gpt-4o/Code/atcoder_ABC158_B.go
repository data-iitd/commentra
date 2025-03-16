package main

import (
	"fmt"
)

func main() {
	var N, A, B int
	fmt.Scan(&N, &A, &B)

	mod := 1000000007
	ans := 0
	rep := N / (A + B)
	ans += rep * A
	res := N - rep*(A+B)
	if res < A {
		ans += res
	} else {
		ans += A
	}
	fmt.Println(ans)
}

// <END-OF-CODE>
