package main

import (
	"fmt"
	"math"
)

func main() {
	var A, B, H, M int
	fmt.Scan(&A, &B, &H, &M)

	// Calculate the angles for the minute and hour hands in degrees
	mkaku := float64(M) * 6
	hkaku := float64(H)*30 + float64(M)/2

	// Calculate the difference between the two angles
	kaku := math.Abs(mkaku - hkaku)

	// Convert the angle difference to radians
	dkaku := kaku * math.Pi / 180

	// Calculate the cosine of the angle in radians
	cosKaku := math.Cos(dkaku)
	cosKaku *= 2 * float64(A) * float64(B)

	// Calculate the distance using the cosine rule
	ans2 := math.Pow(float64(A), 2) + math.Pow(float64(B), 2) - cosKaku

	// Calculate the square root of the distance
	ans := math.Sqrt(ans2)

	// Print the final answer
	fmt.Println(ans)
}
