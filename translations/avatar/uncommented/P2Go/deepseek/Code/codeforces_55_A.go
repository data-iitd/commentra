package main

import (
	"fmt"
	"math"
)

func main() {
	var n float64
	fmt.Scan(&n)
	for n > 1 && n == math.Trunc(n) {
		n /= 2
	}
	if n == 1 {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}
