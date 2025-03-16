package main

import (
	"fmt"
)

func main() {
	var a, b, c, d, e, f int
	var x, y float64

	for {
		_, err := fmt.Scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f)
		if err != nil {
			break
		}

		y = float64(c*d-f*a) / float64(b*d-e*a)
		x = float64(c*e-f*b) / float64(a*e-d*b)

		if y <= 0 && y > -0.0005 {
			y = 0
		}
		if x <= 0 && x > -0.0005 {
			x = 0
		}

		fmt.Printf("%.3f %.3f\n", x, y)
	}
}

// <END-OF-CODE>
