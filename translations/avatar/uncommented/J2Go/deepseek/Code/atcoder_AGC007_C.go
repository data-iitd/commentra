package main

import (
	"fmt"
	"math"
	"math/big"
)

func main() {
	var N, d, x float64
	fmt.Scan(&N, &d, &x)
	ans := big.NewFloat(0.0)
	for N > 0.5 {
		adnum := big.NewFloat(0.0).Add(big.NewFloat(d+x*(N-0.5)), ans)
		ans = adnum
		d = (N+1.0)*d/N + (5.0*x)/(2.0*N)
		x = (1.0 + (2.0 / N)) * x
		N--
	}
	format := fmt.Sprintf("%.20f", ans)
	fmt.Println(format)
}

