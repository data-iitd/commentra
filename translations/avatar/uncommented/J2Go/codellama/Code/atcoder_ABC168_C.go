package main

import (
	"fmt"
	"math"
	"math/big"
)

func main() {
	var A, B, H, M int
	var AA, BB, HH, MM big.Float
	var ans2, kaku, mkaku, hkaku, AA2, BB2, CC, DD big.Float
	var dkaku float64
	var dans2 float64
	fmt.Scan(&A, &B, &H, &M)
	AA.SetFloat64(float64(A))
	BB.SetFloat64(float64(B))
	HH.SetFloat64(float64(H))
	MM.SetFloat64(float64(M))
	mkaku.Mul(MM, big.NewFloat(6))
	hkaku.Mul(HH, big.NewFloat(30))
	hkaku.Add(&hkaku, big.NewFloat(float64(M)/2))
	kaku.Sub(&mkaku, &hkaku)
	dkaku = math.Abs(math.ToRadians(kaku.Float64()))
	AA2.Mul(&AA, &AA)
	BB2.Mul(&BB, &BB)
	CC.Add(&AA2, &BB2)
	DD.Mul(&DD, big.NewFloat(2))
	DD.Mul(&DD, &AA)
	DD.Mul(&DD, &BB)
	ans2.Sub(&CC, &DD)
	dans2 = ans2.Float64()
	ans := math.Sqrt(dans2)
	fmt.Println(ans)
}

