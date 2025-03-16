
###
package main

import (
	"bufio"
	"fmt"
	"math/big"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Initialize a scanner object for reading input
	scanner := bufio.NewScanner(os.Stdin)

	// Read input values for n and m
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	m, _ := strconv.Atoi(scanner.Text())

	// Calculate the greatest common divisor (GCD) of n and m
	gcd := new(big.Int).SetInt64(int64(n)).GCD(nil, nil, big.NewInt(int64(m)))

	// Read input strings s and t
	scanner.Scan()
	s := scanner.Text()
	scanner.Scan()
	t := scanner.Text()

	// Perform the required calculation and print the result
	result := int64(-1)
	for k := 0; k < int(gcd.Int64()); k++ {
		if s[k*n/int(gcd.Int64())]!= t[k*m/int(gcd.Int64())] {
			result = -1
			break
		}
	}
	if result == -1 {
		result = new(big.Int).SetInt64(int64(n)).Mul(new(big.Int).SetInt64(int64(m)), big.NewInt(1).Div(gcd, big.NewInt(1)))
	}

	// Print the result
	fmt.Println(result)
}
###
