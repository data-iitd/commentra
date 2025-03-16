
package main

import (
	"fmt"
	"math"
)

func main() {
	var n int
	fmt.Scan(&n)

	x := 1
	for {
		if math.Log2(float64(n)) == math.Trunc(math.Log2(float64(n))) {
			break
		}

		x++
		n -= int(math.Pow(2, math.Trunc(math.Log2(float64(n)))))
	}

	fmt.Println(x)
}

