package main

import (
	"fmt"
	"math/big"
)

func C(n, m int) *big.Int {
	res := big.NewInt(1)
	for i := m - n + 1; i <= m; i++ {
		res.Mul(res, big.NewInt(int64(i)))
	}
	for i := 1; i <= n; i++ {
		res.Div(res, big.NewInt(int64(i)))
	}
	return res
}

func main() {
	var n, p int
	var k0, k1 int
	fmt.Scan(&n, &p)

	for i := 0; i < n; i++ {
		var x int
		fmt.Scan(&x)
		if x%2 == 1 {
			k1++
		} else {
			k0++
		}
	}

	ans := big.NewInt(1)
	for i := 0; i < k0; i++ {
		ans.Mul(ans, big.NewInt(2))
	}

	if p == 0 {
		add := big.NewInt(0)
		for i := 0; i <= k1; i += 2 {
			add.Add(add, C(i, k1))
		}
		ans.Mul(ans, add)
		fmt.Println(ans)
	} else {
		add := big.NewInt(0)
		for i := 1; i <= k1; i += 2 {
			add.Add(add, C(i, k1))
		}
		ans.Mul(ans, add)
		fmt.Println(ans)
	}
}

// <END-OF-CODE>
