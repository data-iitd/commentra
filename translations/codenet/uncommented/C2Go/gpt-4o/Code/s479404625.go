package main

import (
	"fmt"
	"strings"
)

func main() {
	var A, B, C string

	fmt.Scan(&A, &B, &C)

	la := len(A)
	lb := len(B)

	if A[la-1] == B[0] && B[lb-1] == C[0] {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

// <END-OF-CODE>
