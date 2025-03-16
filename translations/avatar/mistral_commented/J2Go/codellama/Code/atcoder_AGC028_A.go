#######
// Import necessary libraries
#######
import (
	"fmt"
	"math/big"
	"os"
	"strconv"
)

// Main method to start the program
func main() {
	// Read input values for n and m
	n, _ := strconv.Atoi(os.Args[1])
	m, _ := strconv.Atoi(os.Args[2])

	// Calculate the greatest common divisor (GCD) of n and m
	gcd := new(big.Int).GCD(nil, nil, big.NewInt(int64(n)), big.NewInt(int64(m))).Int64()

	// Read input strings s and t
	s := os.Args[3]
	t := os.Args[4]

	// Perform the required calculation and print the result
	result := big.NewInt(0)
	for k := int64(0); k < gcd; k++ {
		if s[k*n/gcd] != t[k*m/gcd] {
			result.SetInt64(-1)
			break
		}
	}
	if result.Int64() == -1 {
		result.Mul(big.NewInt(n), big.NewInt(m))
		result.Div(result, big.NewInt(gcd))
	}

	// Print the result
	fmt.Println(result)
}


