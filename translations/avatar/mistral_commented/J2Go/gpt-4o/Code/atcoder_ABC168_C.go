package main

import (
	"fmt"
	"math"
	"math/big"
)

func main() {
	var A, B, H, M int
	fmt.Scan(&A, &B, &H, &M) // Reading input values

	// Creating big.Float objects for the input values
	AA := new(big.Float).SetInt(big.NewInt(int64(A)))
	BB := new(big.Float).SetInt(big.NewInt(int64(B)))
	HH := new(big.Float).SetInt(big.NewInt(int64(H)))
	MM := new(big.Float).SetInt(big.NewInt(int64(M)))

	// Declaring variables for intermediate calculations
	var ans2, kaku, mkaku, hkaku, AA2, BB2, CC, DD *big.Float
	var dkaku float64
	var dans2 float64

	// Calculating mkaku (M multiplied by 6) and hkaku (H multiplied by 30 and added half of M)
	mkaku = new(big.Float).Mul(MM, big.NewFloat(6))
	hkaku = new(big.Float).Add(new(big.Float).Mul(HH, big.NewFloat(30)), new(big.Float).Quo(MM, big.NewFloat(2)))

	// Calculating kaku (difference between mkaku and hkaku)
	kaku = new(big.Float).Sub(mkaku, hkaku)

	// Calculating the absolute value of kaku in radians
	dkaku = math.Abs(kaku.Float64() * (math.Pi / 180)) // Convert to radians

	// Calculating squared values of A and B
	AA2 = new(big.Float).Mul(AA, AA)
	BB2 = new(big.Float).Mul(BB, BB)

	// Calculating CC (sum of squares of A and B) and DD (cosine of kaku multiplied by A and B)
	CC = new(big.Float).Add(AA2, BB2)
	DD = new(big.Float).Mul(new(big.Float).SetFloat64(math.Cos(dkaku)), new(big.Float).Mul(AA, BB))

	// Calculating the answer (square root of the difference between CC and DD)
	ans2 = new(big.Float).Sub(CC, DD)
	dans2, _ = ans2.Float64() // Convert to float64
	ans := math.Sqrt(dans2)

	// Printing the answer
	fmt.Println(ans)
}

// <END-OF-CODE>
