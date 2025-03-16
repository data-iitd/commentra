package main

import (
	"fmt"
	"math"
	"math/big"
)

func main() {
	// Create a Scanner object to read input from the user
	sc := new(big.Int)

	// Read integer inputs A, B, H, and M from the user
	A := sc.Int64()
	B := sc.Int64()
	H := sc.Int64()
	M := sc.Int64()

	// Convert integer inputs to BigDecimal for precise calculations
	AA := big.NewFloat(float64(A))
	BB := big.NewFloat(float64(B))
	HH := big.NewFloat(float64(H))
	MM := big.NewFloat(float64(M))

	// Declare variables for calculations
	ans2 := big.NewFloat(0)
	kaku := big.NewFloat(0)
	mkaku := big.NewFloat(0)
	hkaku := big.NewFloat(0)
	AA2 := big.NewFloat(0)
	BB2 := big.NewFloat(0)
	CC := big.NewFloat(0)
	DD := big.NewFloat(0)
	dkaku := 0.0
	dans2 := 0.0

	// Calculate the angle of the minute hand in degrees
	mkaku = big.NewFloat(float64(M) * 6)

	// Calculate the angle of the hour hand in degrees
	hkaku = big.NewFloat(float64(H) * 30)
	hkaku = big.NewFloat(float64(H) * 30 + float64(M)/2)

	// Calculate the difference in angles between the two hands
	kaku = mkaku.Sub(hkaku, 0)

	// Convert the angle difference from degrees to radians
	dkaku = math.Abs(math.ToRadians(kaku.Float64()))

	// Calculate the squares of A and B
	AA2 = AA.Mul(AA, 0)
	BB2 = BB.Mul(BB, 0)

	// Calculate the sum of squares of A and B
	CC = AA2.Add(BB2, 0)

	// Calculate the cosine of the angle difference and adjust for the formula
	DD = big.NewFloat(math.Cos(dkaku))
	DD = DD.Mul(big.NewFloat(2), 0)
	DD = DD.Mul(AA, 0)
	DD = DD.Mul(BB, 0)

	// Calculate the final result using the derived formula
	ans2 = CC.Sub(DD, 0)

	// Convert the result to double for square root calculation
	dans2 = ans2.Float64()

	// Calculate the square root of the result
	ans := math.Sqrt(dans2)

	// Output the final result
	fmt.Println(ans)
}

