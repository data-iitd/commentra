package main

import (
	"fmt"
	"math"
)

func main() {
	var x1, y1, x2, y2 int
	fmt.Scan(&x1, &y1, &x2, &y2)

	denominator := x2 - x1
	numerator := y2 - y1

	if denominator != 0 {
		quotient := float64(numerator) / float64(denominator)

		if numerator == 0 {
			d := int(math.Sqrt(float64((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1))))
			x3, y3 := x2, y2+d
			x4, y4 := x1, y1+d
			fmt.Printf("%d %d %d %d\n", x3, y3, x4, y4)
		} else if quotient == 1 {
			x3, y3 := x1, y1
			x4, y4 := x2, y2
			fmt.Printf("%d %d %d %d\n", x3, y3, x4, y4)
		} else if quotient == -1 {
			x3, y3 := x2, y2
			x4, y4 := x1, y1
			fmt.Printf("%d %d %d %d\n", x3, y3, x4, y4)
		} else {
			fmt.Println("-1")
		}
	} else {
		y4, y3 := y2, y1
		d := int(math.Sqrt(float64((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1))))
		x4, x3 := x1+d, x2+d
		fmt.Printf("%d %d %d %d\n", x3, y3, x4, y4)
	}
}

// <END-OF-CODE>
