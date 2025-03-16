package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var N, S, M, m, addup, i int
	for {
		if _, err := fmt.Scanf("%d", &N); err!= nil || N == 0 {
			break
		}
		M = -1
		m = 1001
		addup = 0
		for i = 0; i < N; i++ {
			fmt.Scanf("%d", &S)
			addup += S
			if S > M {
				M = S
			}
			if S < m {
				m = S
			}
		}
		fmt.Printf("%d\n", (addup-M-m)/(N-2))
	}
}

