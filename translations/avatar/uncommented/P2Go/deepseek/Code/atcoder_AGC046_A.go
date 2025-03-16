package main

import (
	"fmt"
	"math/big"
)

func gcd(a, b int) int {
	return int(new(big.Int).GCD(nil, nil, big.NewInt(int64(a)), big.NewInt(int64(b))).Int64())
}

func main() {
	var x int
	fmt.Scan(&x)
	fmt.Println(360 / gcd(360, x))
}
