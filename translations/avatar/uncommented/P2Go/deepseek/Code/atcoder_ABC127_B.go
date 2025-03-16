package main

import (
	"fmt"
	"math"
)

func main() {
	var r, D, x int
	fmt.Scan(&r, &D, &x)
	for i := 2; i <= 11; i++ {
		result := (math.Pow(float64(r), float64(i-1)) * (float64(x) + float64(D)/(1-float64(r))) - float64(D)/(1-float64(r)))
		fmt.Println(int(result))
	}
}

