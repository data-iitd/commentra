package main

import (
	"fmt"
)

func main() {
	var A, B, C, X int
	kosu := 0

	// 整数の入力
	fmt.Scan(&A)
	fmt.Scan(&B)
	fmt.Scan(&C)
	fmt.Scan(&X)

	X = X / 50

	for i := 0; i <= A; i++ {
		for j := 0; j <= B; j++ {
			for k := 0; k <= C; k++ {
				if X == (10*i)+(2*j)+k {
					kosu++
				}
			}
		}
	}

	fmt.Println(kosu)
}

// <END-OF-CODE>
