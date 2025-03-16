package main

import (
	"fmt"
	"math"
)

func main() {
	var n int
	fmt.Scan(&n)

	for i := 1; i <= n; i++ {
		x := i
		if x%3 == 0 || x%10 == 3 {
			fmt.Print(" ", i)
			continue
		} else {
			k := int(math.Log10(float64(x))) + 1 // Get the number of digits
			for k > 0 {
				k--
				j := int(math.Pow(10, float64(k)))
				if (x/j)%10 == 3 {
					fmt.Print(" ", i)
					break
				}
			}
		}
	}
	fmt.Println()
}

// <END-OF-CODE>
