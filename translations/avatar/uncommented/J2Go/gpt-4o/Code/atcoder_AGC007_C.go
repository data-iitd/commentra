package main

import (
	"fmt"
	"math/big"
)

func main() {
	var N float64
	var d float64
	var x float64

	fmt.Scan(&N, &d, &x)

	ans := new(big.Float).SetFloat64(0.0)

	for N > 0.5 {
		adnum := new(big.Float).SetFloat64(d + x*(N-0.5))
		ans = new(big.Float).Add(ans, adnum)

		d = (N+1.0)*d/N + (5.0*x)/(2.0*N)
		x = (1.0 + (2.0 / N)) * x
		N--
	}

	// Format the output to have at least 20 decimal places
	fmt.Printf("%.20f\n", ans)
}

// <END-OF-CODE>
