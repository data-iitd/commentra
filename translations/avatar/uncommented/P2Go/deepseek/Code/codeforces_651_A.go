package main

import (
	"fmt"
	"math"
)

func main() {
	var x, y int
	fmt.Scan(&x, &y)
	result := int(math.Max(float64(x+y-3+(y-x)%3 > 0), 0))
	fmt.Println(result)
}

