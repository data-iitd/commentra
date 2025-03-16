package main

import (
	"fmt"
	"math/big"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read two integers n and m from input
	n, _ := strconv.Atoi(os.Args[1])
	m, _ := strconv.Atoi(os.Args[2])

	// Calculate the greatest common divisor (gcd) of n and m
	gcd := big.NewInt(int64(n)).GCD(nil, big.NewInt(int64(m))).Int64()

	// Read two strings s and t from input
	s := os.Args[3]
	t := os.Args[4]

	// Check for mismatches in the characters of the two strings based on the gcd
	// If a mismatch is found, return -1; otherwise, return the least common multiple (lcm) of n and m
	fmt.Println(
		strings.Split(s, "")[:gcd]!= strings.Split(t, "")[:gcd] {
			fmt.Println(-1)
		} else {
			fmt.Println(big.NewInt(int64(n)).Mul(big.NewInt(int64(m)), big.NewInt(gcd)).Int64() / gcd)
		}
	)
}

