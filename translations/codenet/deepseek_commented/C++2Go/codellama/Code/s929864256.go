package main

import (
	"fmt"
	"math"
)

func main() {
	var a, b int64
	fmt.Scan(&a, &b)

	max := int64(math.MaxInt64)
	fmt.Println(max(a+b, max(a-b, a*b)))
}

