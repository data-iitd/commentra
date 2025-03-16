
package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a scanner object to read input from the user
	sc := bufio.NewScanner(os.Stdin)

	// Read integer inputs A, B, H, and M from the user
	sc.Scan()
	A, _ := strconv.Atoi(sc.Text())
	sc.Scan()
	B, _ := strconv.Atoi(sc.Text())
	sc.Scan()
	H, _ := strconv.Atoi(sc.Text())
	sc.Scan()
	M, _ := strconv.Atoi(sc.Text())

	// Convert integer inputs to float64 for precise calculations
	AA := float64(A)
	BB := float64(B)
	HH := float64(H)
	MM := float64(M)

	// Declare variables for calculations
	var ans2, kaku, mkaku, hkaku, AA2, BB2, CC, DD float64

	// Calculate the angle of the minute hand in degrees
	mkaku = MM * 6

	// Calculate the angle of the hour hand in degrees
	hkaku = HH*30 + MM/2

	// Calculate the difference in angles between the two hands
	kaku = mkaku - hkaku

	// Convert the angle difference from degrees to radians
	dkaku := math.Abs(math.ToRadians(kaku))

	// Calculate the squares of A and B
	AA2 = AA * AA
	BB2 = BB * BB

	// Calculate the sum of squares of A and B
	CC = AA2 + BB2

	// Calculate the cosine of the angle difference and adjust for the formula
	DD = math.Cos(dkaku) * 2 * AA * BB

	// Calculate the final result using the derived formula
	ans2 = CC - DD

	// Calculate the square root of the result
	ans := math.Sqrt(ans2)

	// Output the final result
	fmt.Println(ans)
}

