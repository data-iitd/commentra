package main

import (
	"fmt"
	"math"
)

func main() {
	var A, B, H, M int
	fmt.Scan(&A, &B, &H, &M)

	AA := float64(A)
	BB := float64(B)
	HH := float64(H)
	MM := float64(M)

	var mkaku, hkaku, kaku float64
	mkaku = MM * 6
	hkaku = HH * 30 + (MM / 2)
	kaku = mkaku - hkaku

	dkaku := math.Abs(kaku * (math.Pi / 180)) // Convert degrees to radians

	AA2 := AA * AA
	BB2 := BB * BB
	CC := AA2 + BB2

	DD := 2 * math.Cos(dkaku) * AA * BB
	ans2 := CC - DD

	ans := math.Sqrt(ans2)
	fmt.Println(ans)
}

// <END-OF-CODE>
