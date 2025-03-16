package main

import (
	"fmt"
)

func main() {
	var a float64
	ave := 0.0

	for i := 0; i < 5; i++ {
		fmt.Scanf("%lf", &a)
		if a <= 40 {
			ave += 40
		} else {
			ave += a
		}
	}

	ave /= 5.0

	fmt.Printf("%.0f\n", ave)
}

// <END-OF-CODE>
