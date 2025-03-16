package main

import (
	"fmt"
	"math"
	"math/big"
)

func main() {
	var A, B, H, M int
	fmt.Scan(&A, &B, &H, &M)

	// Creating big.Int objects for the input values
	AA := big.NewInt(int64(A))
	BB := big.NewInt(int64(B))
	HH := big.NewInt(int64(H))
	MM := big.NewInt(int64(M))

	// Calculating mkaku (M multiplied by 6) and hkaku (H multiplied by 30 and added half of M)
	mkaku := new(big.Int).Mul(MM, big.NewInt(6))
	hkaku := new(big.Int).Mul(HH, big.NewInt(30))
	hkaku.Add(hkaku, new(big.Int).Div(MM, big.NewInt(2)))

	// Calculating kaku (difference between mkaku and hkaku)
	kaku := new(big.Int).Sub(mkaku, hkaku)
	kaku.Abs(kaku)

	// Calculating the absolute value of kaku in radians
	dkaku := math.Abs(float64(kaku.Int64()))

	// Calculating the squared values of A and B
	AA2 := new(big.Int).Mul(AA, AA)
	BB2 := new(big.Int).Mul(BB, BB)

	// Calculating CC (sum of squares of A and B) and DD (cosine of kaku multiplied by A and B)
	CC := new(big.Int).Add(AA2, BB2)
	DD := new(big.Float).Mul(big.NewFloat(math.Cos(dkaku)), big.NewFloat(float64(A)).Mul(big.NewFloat(float64(B))))

	// Calculating the answer (square root of the difference between CC and DD)
	ans2 := new(big.Float).Sub(big.NewFloat(float64(CC.Int64())), DD)
	var dans2 float64
	ans2.Float64(&dans2)
	ans := math.Sqrt(dans2)

	// Printing the answer
	fmt.Println(ans)
}
