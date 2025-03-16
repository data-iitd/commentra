package main

import (
	"fmt"
	"math"
	"math/big"
)

func main() {
	var A, B, H, M int
	fmt.Scan(&A, &B, &H, &M)

	AA := big.NewFloat(float64(A))
	BB := big.NewFloat(float64(B))
	HH := big.NewFloat(float64(H))
	MM := big.NewFloat(float64(M))

	mkaku := new(big.Float).Mul(MM, big.NewFloat(6))
	hkaku := new(big.Float).Mul(HH, big.NewFloat(30)).Add(MM.Mul(big.NewFloat(0.5)))
	kaku := new(big.Float).Sub(mkaku, hkaku)

	dkaku := math.Abs(math.Cos(kaku.Float64()))

	AA2 := new(big.Float).Mul(AA, AA)
	BB2 := new(big.Float).Mul(BB, BB)
	CC := new(big.Float).Add(AA2, BB2)
	DD := new(big.Float).Mul(big.NewFloat(dkaku), AA).Mul(BB)

	ans2 := new(big.Float).Sub(CC, DD)
	ans := math.Sqrt(ans2.Float64())

	fmt.Println(ans)
}

