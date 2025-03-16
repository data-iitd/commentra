package main

import (
	"fmt"
	"math"
)

func main() {
	var x int
	fmt.Scan(&x)

	if x != 2 && x%2 == 0 {
		x++
	}

	for {
		sqrtNum := math.Sqrt(float64(x))
		i := 3
		for i <= int(sqrtNum) {
			if x%i == 0 {
				break
			}
			i += 2
		}
		if i > int(sqrtNum) {
			break
		}
		x += 2
	}

	fmt.Println(x)
}

// <END-OF-CODE>
