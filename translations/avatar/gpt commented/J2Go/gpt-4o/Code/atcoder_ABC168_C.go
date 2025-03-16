package main

import (
	"fmt"
	"math"
)

func main() {
	// Read integer inputs A, B, H, and M from the user
	var A, B, H, M int
	fmt.Scan(&A, &B, &H, &M)

	// Calculate the angle of the minute hand in degrees
	mkaku := float64(M) * 6

	// Calculate the angle of the hour hand in degrees
	hkaku := float64(H)*30 + float64(M)/2

	// Calculate the difference in angles between the two hands
	kaku := mkaku - hkaku

	// Convert the angle difference from degrees to radians
	dkaku := math.Abs(kaku * (math.Pi / 180))

	// Calculate the squares of A and B
	AA2 := float64(A * A)
	BB2 := float64(B * B)

	// Calculate the sum of squares of A and B
	CC := AA2 + BB2

	// Calculate the cosine of the angle difference and adjust for the formula
	DD := 2 * float64(A) * float64(B) * math.Cos(dkaku)

	// Calculate the final result using the derived formula
	ans2 := CC - DD

	// Calculate the square root of the result
	ans := math.Sqrt(ans2)

	// Output the final result
	fmt.Println(ans)
}

// <END-OF-CODE>
