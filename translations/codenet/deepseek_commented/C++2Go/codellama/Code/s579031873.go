package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
)

func main() {
	var N, X int
	fmt.Scan(&N, &X)

	var ans int = 0
	var min int = 1000000000
	for i := 0; i < N; i++ {
		var tmp int
		fmt.Scan(&tmp)
		X -= tmp
		ans++
		if tmp < min {
			min = tmp
		}
	}

	ans += X / min

	fmt.Println(ans)
}

