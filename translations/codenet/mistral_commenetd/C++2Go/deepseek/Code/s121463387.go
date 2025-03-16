package main

import (
	"fmt"
	"strconv"
	"math"
)

func main() {
	var n, x int
	var s string

	fmt.Scan(&n)

	for i := 1; i <= n; i++ {
		x = i
		s = strconv.Itoa(x)

		if x % 3 == 0 || x % 10 == 3 {
			fmt.Print(" ", i)
			continue
		} else {
			k := len(s)

			for k > 0 {
				k--
				j := int(math.Pow(10, float64(k)))

				if (x / j) % 10 == 3 {
					fmt.Print(" ", i)
					break
				}
			}
		}
	}
	fmt.Println()
}

