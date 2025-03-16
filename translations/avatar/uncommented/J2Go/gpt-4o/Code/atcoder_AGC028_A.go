package main

import (
	"fmt"
	"math/big"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	gcd := new(big.Int).GCD(nil, nil, big.NewInt(int64(n)), big.NewInt(int64(m))).Int64()

	var s, t string
	fmt.Scan(&s, &t)

	result := int64(n * m / gcd)
	for k := int64(0); k < gcd; k++ {
		if s[k*n/gcd] != t[k*m/gcd] {
			result = -1
			break
		}
	}

	fmt.Println(result)
}

// <END-OF-CODE>
