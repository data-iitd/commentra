package main

import (
	"fmt"
)

func main() {
	var A, B, C, X int
	fmt.Scan(&A, &B, &C, &X)

	X /= 50
	count := 0

	for i := 0; i <= A; i++ {
		for j := 0; j <= B; j++ {
			for k := 0; k <= C; k++ {
				if X == (10*i)+(2*j)+k {
					count++
				}
			}
		}
	}

	fmt.Println(count)
}

