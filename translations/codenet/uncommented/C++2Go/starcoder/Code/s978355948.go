package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	N, X := 0, 0
	fmt.Scanf("%d %d", &N, &X)
	L := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scanf("%d", &L[i])
	}

	var i int
	var d int
	for i = 0; i < N; i++ {
		d = d + L[i]
		if d > X {
			break
		}
	}

	fmt.Printf("%d\n", i+1)
}

