package main

import (
	"fmt"
	"math/big"
	"os"
	"strconv"
)

func main() {
	n, _ := strconv.Atoi(os.Args[1])
	m, _ := strconv.Atoi(os.Args[2])
	gcd := big.NewInt(int64(n)).GCD(nil, nil, big.NewInt(int64(m))).Int64()
	s := os.Args[3]
	t := os.Args[4]
	fmt.Println(big.NewInt(int64(n)).Mul(big.NewInt(int64(m)), big.NewInt(int64(gcd))).Div(big.NewInt(int64(gcd)), big.NewInt(int64(n))).Div(big.NewInt(int64(gcd)), big.NewInt(int64(m))).Int64())
}

