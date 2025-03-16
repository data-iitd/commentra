package main

import (
	"fmt"
	"sort"
	"strings"
	"math"
)

const (
	mod     = 1000000007
	mod9    = 998244353
	epsilon = 1e-7
)

func main() {
	var tc, n, m int
	fmt.Scan(&tc, &n, &m)
	if n > m {
		n, m = m, n
	}
	fl := false
	for i := 1; i <= m; i++ {
		if i*tc >= n && i*tc <= m {
			fmt.Println("OK")
			fl = true
			break
		}
	}
	if !fl {
		fmt.Println("NG")
	}
}

