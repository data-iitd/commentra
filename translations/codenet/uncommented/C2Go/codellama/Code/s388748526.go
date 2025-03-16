package main

import (
	"fmt"
	"math"
)

func main() {
	var r float64
	fmt.Scanf("%f", &r)
	fmt.Printf("%f %f\n", r*r*math.Pi, 2*math.Pi*r)
}

