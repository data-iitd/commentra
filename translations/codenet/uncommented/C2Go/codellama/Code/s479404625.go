package main

import (
	"fmt"
	"strings"
)

func main() {
	var A, B, C string

	fmt.Scan(&A, &B, &C)

	if A[len(A)-1] == B[0] && B[len(B)-1] == C[0] {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

