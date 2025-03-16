package main

import (
	"fmt"
	"math/big"
)

func main() {
	var s string
	var l int = 2019
	var m = make([]int, l)
	var a, r int
	m[0] = 1

	fmt.Scan(&s)

	for i := len(s) - 1; i >= 0; i-- {
		a += int(s[i]-'0') * int(big.NewInt(int64(i)).Mod(big.NewInt(int64(i)), big.NewInt(int64(l))).Int64())
		r += m[a%l]
		m[a%l]++
	}

	fmt.Println(r)
}

