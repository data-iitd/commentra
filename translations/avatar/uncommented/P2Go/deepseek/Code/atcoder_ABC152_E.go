package main

import (
	"fmt"
	"math/big"
)

func gcd(a, b int) int {
	for b != 0 {
		a, b = b, a % b
	}
	return a
}

func lcm(a, b int) int {
	return a * b / gcd(a, b)
}

const MOD = 1000000007

func main() {
	var N int
	fmt.Scan(&N)
	var A []int
	for i := 0; i < N; i++ {
		var x int
		fmt.Scan(&x)
		A = append(A, x)
	}
	_lcm := 1
	for _, a := range A {
		_lcm = _lcm * a / gcd(_lcm, a)
	}
	ans := new(big.Int).Mul(_lcm, new(big.Int).SetInt64(int64(N)))
	for _, s := range A {
		inv := new(big.Int).ModInverse(new(big.Int).SetInt64(int64(s)), big.NewInt(MOD))
		ans.Add(ans, inv)
	}
	ans.Mod(ans, big.NewInt(MOD))
	fmt.Println(ans)
}
