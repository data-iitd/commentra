package main

import (
	"fmt"
	"math/big"
	"os"
	"strconv"
	"strings"
)

func main() {
	n, _ := strconv.Atoi(os.Args[1])
	m, _ := strconv.Atoi(os.Args[2])
	gcd := big.NewInt(0).GCD(big.NewInt(int64(n)), big.NewInt(int64(m))).Int64()
	s := os.Args[3]
	t := os.Args[4]
	fmt.Println(
		strings.IndexFunc(
			strings.Repeat(s, gcd/n),
			func(r rune) bool { return r!= t[len(t)/gcd*r] }))
}

