package main

import (
	"fmt"
	"math"
	"math/big"
)

func main() {
	// Create a Scanner object to read input from the user
	var A, B, H, M int
	fmt.Scan(&A, &B, &H, &M)
	
	// Convert integer inputs to big.Rat for precise calculations
	AA := new(big.Rat).SetInt(big.NewInt(int64(A)))
	BB := new(big.Rat).SetInt(big.NewInt(int64(B)))
	HH := new(big.Rat).SetInt(big.NewInt(int64(H)))
	MM := new(big.Rat).SetInt(big.NewInt(int64(M)))
	
	// Declare variables for calculations
	var ans2 *big.Rat
	var kaku, mkaku, hkaku, AA2, BB2, CC, DD *big.Rat
	var dkaku float64
	var dans2 float64
	
	// Calculate the angle of the minute hand in degrees
	mkaku = new(big.Rat).Mul(MM, big.NewRat(6, 1))
	
	// Calculate the angle of the hour hand in degrees
	hkaku = new(big.Rat).Mul(HH, big.NewRat(30, 1))
	hkaku.Add(hkaku, new(big.Rat).Mul(big.NewRat(1, 2), MM))
	
	// Calculate the difference in angles between the two hands
	kaku = new(big.Rat).Sub(mkaku, hkaku)
	
	// Convert the angle difference from degrees to radians
	dkaku = math.Abs(math.Cos(kaku.Float64()))
	
	// Calculate the squares of A and B
	AA2 = new(big.Rat).Mul(AA, AA)
	BB2 = new(big.Rat).Mul(BB, BB)
	
	// Calculate the sum of squares of A and B
	CC = new(big.Rat).Add(AA2, BB2)
	
	// Calculate the cosine of the angle difference and adjust for the formula
	DD = new(big.Rat).Mul(big.NewRat(2, 1), new(big.Rat).Mul(AA, BB))
	DD.Mul(DD, new(big.Rat).SetFloat64(math.Cos(dkaku)))
	
	// Calculate the final result using the derived formula
	ans2 = new(big.Rat).Sub(CC, DD)
	
	// Convert the result to float64 for square root calculation
	dans2 = ans2.Float64()
	
	// Calculate the square root of the result
	ans := math.Sqrt(dans2)
	
	// Output the final result
	fmt.Println(ans)
}
