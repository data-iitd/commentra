package main

import (
	"fmt"
	"math"
)

func main() {
	var n, d int
	fmt.Scan(&n, &d)

	a := d*2 + 1
	fmt.Println(math.Ceil(float64(n) / a))
}

