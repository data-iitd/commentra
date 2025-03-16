package main

import (
	"fmt"
	"math/big"
	"os"
	"strconv"
)

func main() {
	var n, m int
	var s, t string

	// Reading the first integer
	_, err := fmt.Scan(&n)
	if err != nil {
		fmt.Println(err)
		os.Exit(1)
	}

	// Reading the second integer
	_, err = fmt.Scan(&m)
	if err != nil {
		fmt.Println(err)
		os.Exit(1)
	}

	// Reading the first string
	_, err = fmt.Scan(&s)
	if err != nil {
		fmt.Println(err)
		os.Exit(1)
	}

	// Reading the second string
	_, err = fmt.Scan(&t)
	if err != nil {
		fmt.Println(err)
		os.Exit(1)
	}

	// Calculating the GCD of n and m
	gcd := big.NewInt(int64(n)).GCD(nil, nil, big.NewInt(int64(m))).Int64()

	// Filtering the range of the GCD and checking character mismatches
	for i := 0; i < int(gcd); i++ {
		if s[i*n/gcd] != t[i*m/gcd] {
			fmt.Println(-1)
			os.Exit(1)
		}
	}

	// Calculating and printing the result
	fmt.Println(big.NewInt(int64(n)).Mul(big.NewInt(int64(m)), big.NewInt(int64(gcd))).Div(big.NewInt(int64(gcd)), big.NewInt(int64(gcd))).Int64())
}

