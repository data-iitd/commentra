package main

import (
	"fmt"
)

func main() {
	var A, B, C, D, E, max int
	fmt.Scanf("%d %d", &A, &B)
	C = A + B
	D = A - B
	E = A * B
	max = C
	if max < D {
		max = D
	}
	if max < E {
		max = E
	}
	fmt.Println(max)
}

// <END-OF-CODE>
