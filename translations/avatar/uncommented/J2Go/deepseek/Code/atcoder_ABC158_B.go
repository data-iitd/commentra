package main

import (
	"fmt"
	"math"
)

func main() {
	var N, A, B float64
	fmt.Scan(&N, &A, &B)

	if 1 <= N && N <= math.Pow(10, 18) && 0 <= A && 0 <= B && 0 < A+B && A+B <= math.Pow(10, 18) {
		if A+B <= N {
			k := N / (A + B)
			if N-k*(A+B) > A {
				fmt.Println(A*k + (N - k*(A+B)) - (N - (k*(A+B)+A)))
			} else {
				fmt.Println(A*k + (N - k*(A+B)))
			}
		} else if A+B > N && A <= N {
			fmt.Println(A)
		} else {
			fmt.Println(N)
		}
	}
}
