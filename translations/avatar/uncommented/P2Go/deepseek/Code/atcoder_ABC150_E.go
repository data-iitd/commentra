package main

import (
	"fmt"
	"math/big"
)

const mod = 1000000007

func main() {
	var n int
	fmt.Scan(&n)

	var c []int
	var x int
	for i := 0; i < n; i++ {
		fmt.Scan(&x)
		c = append(c, x)
	}

	// Sort the array in descending order
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			if c[i] < c[j] {
				c[i], c[j] = c[j], c[i]
			}
		}
	}

	// Calculate b using big.Int for large exponentiation
	b := new(big.Int).Exp(big.NewInt(2), big.NewInt(2*int64(n)-2), nil)
	b.Mod(b, big.NewInt(mod))

	// Calculate a
	a := new(big.Int).Mul(big.NewInt(2), b)
	a.Mod(a, big.NewInt(mod))

	// Calculate the answer
	ans := big.NewInt(0)
	for i := 0; i < n; i++ {
		term := new(big.Int).Mul(big.NewInt(int64(c[i])), new(big.Int).Add(a, new(big.Int).Mul(big.NewInt(int64(i)), b)))
		term.Mod(term, big.NewInt(mod))
		ans.Add(ans, term)
		ans.Mod(ans, big.NewInt(mod))
	}

	fmt.Println(ans)
}
