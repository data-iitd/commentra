package main

import (
	"fmt"
	"math"
)

func main() {
	var a, b int64
	fmt.Scan(&a, &b)
	fmt.Println(int64(math.Max(float64(a+b), math.Max(float64(a-b), float64(a*b)))))
}

