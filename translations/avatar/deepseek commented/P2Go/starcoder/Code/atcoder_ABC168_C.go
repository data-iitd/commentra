
package main

import (
	"fmt"
	"math"
)

func main() {
	var a, b, h, m int
	fmt.Scanf("%d %d %d %d", &a, &b, &h, &m)
	c := math.Abs(360/60*m-360/12*h-360/12/60*m)
	if c > 180 {
		c = 360 - c
	}
	cosC := math.Cos(math.Pi * c / 180)
	fmt.Printf("%.2f", math.Sqrt(a*a+b*b-2*a*b*cosC))
}

