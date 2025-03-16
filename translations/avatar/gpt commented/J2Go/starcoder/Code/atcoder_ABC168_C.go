package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a new scanner to read from stdin
	reader := bufio.NewReader(os.Stdin)

	// Read the input from stdin
	fmt.Print("Enter A: ")
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)
	A, _ := strconv.Atoi(input)

	fmt.Print("Enter B: ")
	input, _ = reader.ReadString('\n')
	input = strings.TrimSpace(input)
	B, _ := strconv.Atoi(input)

	fmt.Print("Enter H: ")
	input, _ = reader.ReadString('\n')
	input = strings.TrimSpace(input)
	H, _ := strconv.Atoi(input)

	fmt.Print("Enter M: ")
	input, _ = reader.ReadString('\n')
	input = strings.TrimSpace(input)
	M, _ := strconv.Atoi(input)

	// Convert the input to float64 for precise calculations
	AA := float64(A)
	BB := float64(B)
	HH := float64(H)
	MM := float64(M)

	// Declare variables for calculations
	ans2 float64
	kaku float64
	mkaku float64
	hkaku float64
	AA2 float64
	BB2 float64
	CC float64
	DD float64
	dkaku float64
	dans2 float64

	// Calculate the angle of the minute hand in degrees
	mkaku = MM * 6

	// Calculate the angle of the hour hand in degrees
	hkaku = HH * 30
	hkaku = hkaku + (M / 2)

	// Calculate the difference in angles between the two hands
	kaku = mkaku - hkaku

	// Convert the angle difference from degrees to radians
	dkaku = math.Abs(math.ToRadians(kaku))

	// Calculate the squares of A and B
	AA2 = AA * AA
	BB2 = BB * BB

	// Calculate the sum of squares of A and B
	CC = AA2 + BB2

	// Calculate the cosine of the angle difference and adjust for the formula
	DD = math.Cos(dkaku) * 2
	DD = DD * AA
	DD = DD * BB

	// Calculate the final result using the derived formula
	ans2 = CC - DD

	// Convert the result to float64 for square root calculation
	dans2 = ans2

	// Calculate the square root of the result
	ans := math.Sqrt(dans2)

	// Output the final result
	fmt.Println(ans)
}

