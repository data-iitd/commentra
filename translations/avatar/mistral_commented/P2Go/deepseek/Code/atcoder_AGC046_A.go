package main

import (
	"fmt"
	"math/big"
)

func main() {
	// Ask the user for an integer input and assign it to the variable x
	var x int
	fmt.Scan(&x)

	// Calculate the greatest common divisor (gcd) of 360 and the user input x
	gcdValue := new(big.Int).GCD(nil, nil, big.NewInt(360), big.NewInt(int64(x)))

	// Print the result of the division of 360 by the gcd
	fmt.Println(new(big.Int).Div(big.NewInt(360), gcdValue))
}

