package main

import (
	"fmt"
	"math/big"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	gcd := new(big.Int).GCD(nil, nil, big.NewInt(int64(n)), big.NewInt(int64(m)))
	var s, t string
	fmt.Scan(&s, &t)

	gcdValue := gcd.Int64()
	result := (int64(n) * int64(m)) / gcdValue

	foundMismatch := false
	for k := 0; k < int(gcdValue); k++ {
		if s[k*n/int(gcdValue)] != t[k*m/int(gcdValue)] {
			fmt.Println(-1)
			foundMismatch = true
			break
		}
	}

	if !foundMismatch {
		fmt.Println(result)
	}
}
