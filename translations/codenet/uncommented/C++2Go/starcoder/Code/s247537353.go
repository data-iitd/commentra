package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

func main() {
	var A, B, C, K int
	fmt.Scanf("%d %d %d %d", &A, &B, &C, &K)
	if A+B >= K {
		fmt.Println(min(A, K))
	} else {
		fmt.Println(A - (K - (A + B)))
	}
}

