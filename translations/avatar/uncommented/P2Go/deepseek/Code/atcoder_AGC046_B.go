package main

import (
	"fmt"
)

func main() {
	var A, B, C, D, m int
	m = 998244353
	fmt.Scan(&A, &B, &C, &D)
	d := make([][]int, C+1)
	for i := range d {
		d[i] = make([]int, D+1)
	}
	d[A][B] = 1
	for i := A; i <= C; i++ {
		for j := B; j <= D; j++ {
			d[i][j] = (d[i][j] + (d[i][j-1]*i + d[i-1][j]*j - d[i-1][j-1]*(i-1)*(j-1))) % m
		}
	}
	fmt.Println(d[C][D])
}

