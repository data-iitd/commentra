package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

func main() {
	var N, X int
	fmt.Scanf("%d %d\n", &N, &X)

	ans := 0
	min := 1000000000
	for i := 0; i < N; i++ {
		tmp := 0
		fmt.Scanf("%d\n", &tmp)
		X -= tmp
		ans++
		if tmp < min {
			min = tmp
		}
	}

	ans += X / min

	fmt.Printf("%d\n", ans)
}

