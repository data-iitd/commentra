package main

import (
	"fmt"
	"math"
	"strconv"
)

func main() {
	var A, B, C, X int
	var i, j, k int
	var kosu int

	fmt.Scan(&A)
	fmt.Scan(&B)
	fmt.Scan(&C)
	fmt.Scan(&X)

	X = int(math.Floor(float64(X) / 50))

	for i = 0; i <= A; i++ {
		for j = 0; j <= B; j++ {
			for k = 0; k <= C; k++ {
				if X == (10*i) + (2*j) + k {
					kosu++
				}
			}
		}
	}

	fmt.Println(kosu)
}

