package main

import (
	"fmt"
	"math/big"
	"os"
	"strconv"
	"strings"
)

func main() {
	n, m := 0, 0
	fmt.Scanf("%d %d", &n, &m)
	s, t := "", ""
	fmt.Scanf("%s %s", &s, &t)
	gcd := big.NewInt(0).GCD(nil, nil, big.NewInt(int64(n)), big.NewInt(int64(m))).Int64()
	fmt.Println(strings.Count(s[:gcd], t[:gcd]))
}

