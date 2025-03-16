package main

import (
	"fmt"
	"math"
)

func main() {
	var A, B, H, M int
	fmt.Scan(&A, &B, &H, &M)

	// Calculate the angles for the minute and hour hands in degrees
	mkaku := float64(M) * 6 // Minute hand angle
	hkaku := float64(H)*30 + float64(M)/2 // Hour hand angle

	// Calculate the difference between the two angles
	kaku := mkaku - hkaku

	// Convert the angle difference to radians
	dkaku := math.Abs(kaku * (math.Pi / 180))

	// Calculate the cosine of the angle in radians
	AA2 := float64(A * A)
	BB2 := float64(B * B)
	CC := AA2 + BB2
	DD := 2 * float64(A) * float64(B) * math.Cos(dkaku)

	// Calculate the distance using the cosine rule
	ans2 := CC - DD

	// Calculate the square root of the distance
	ans := math.Sqrt(ans2)

	// Print the final answer
	fmt.Println(ans)
}

// <END-OF-CODE>
