package main

import (
	"fmt"
	"math"
)

func main() {
	var a, b, c, d int
	fmt.Scan(&a, &b, &c, &d)
	fmt.Println(int(math.Abs(float64(a-c)) * math.Abs(float64(b-d))))
}

