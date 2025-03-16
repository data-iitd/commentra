package main

import (
	"fmt"
	"math"
	"math/big"
)

func main() {
	var A, B, H, M int
	fmt.Scan(&A, &B, &H, &M)

	AA := big.NewInt(int64(A))
	BB := big.NewInt(int64(B))
	HH := big.NewInt(int64(H))
	MM := big.NewInt(int64(M))

	mkaku := new(big.Rat).SetFloat64(float64(M) * 6)
	hkaku := new(big.Rat).SetFloat64(float64(H)*30 + float64(M)/2)
	kaku := new(big.Rat).Sub(mkaku, hkaku)
	dkaku := math.Abs(math.Mod(kaku.Float64(), 360))

	AA2 := new(big.Int).Mul(AA, AA)
	BB2 := new(big.Int).Mul(BB, BB)
	CC := new(big.Int).Add(AA2, BB2)
	DD := new(big.Rat).SetFloat64(math.Cos(dkaku * math.Pi / 180))
	DD.Mul(DD, big.NewRat(2, 1)).Mul(DD, AA).Mul(DD, BB)
	ans2 := new(big.Int).Sub(CC, new(big.Int).SetBytes(DD.Num().Bytes()))
	dans2 := new(big.Rat).SetFrac(ans2, big.NewInt(1))
	ans := math.Sqrt(dans2.Float64())
	fmt.Println(ans)
}

