
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
	ans := big.NewFloat(0.0)
	for N > 0.5 {
		adnum := big.NewFloat(d + x*(N-0.5))
		ans.Add(ans, adnum)
		d = (N+1.0)*d/N + (5.0*x)/(2.0*N)
		x = (1.0+(2.0/N))*x
		N--
	}
	format := "%.20f"
	fmt.Printf(format, ans)
}

