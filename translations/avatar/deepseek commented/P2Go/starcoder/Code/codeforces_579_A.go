
package main

import (
	"fmt"
	"math"
)

func main() {
	var n int
	fmt.Scanf("%d", &n)
	x := 1
	for math.Log2(float64(n))%1!= 0 {
		x++
		n -= 2 << int(math.Log2(float64(n)))
	}
	fmt.Println(x)
}

