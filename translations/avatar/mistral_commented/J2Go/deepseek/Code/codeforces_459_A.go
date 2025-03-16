package main

import (
	"fmt"
	"math"
)

func main() {
	var x1, y1, x2, y2 int
	fmt.Scan(&x1, &y1, &x2, &y2)

	if x1 == x2 {
		dif := int(math.Abs(float64(y1 - y2)))
		fmt.Println(x1+dif, y1, x1+dif, y2)
	} else if y1 == y2 {
		dif := int(math.Abs(float64(x1 - x2)))
		fmt.Println(x1, y1+dif, x2, y2+dif)
	} else if int(math.Abs(float64(x1-x2))) == int(math.Abs(float64(y1-y2))) {
		fmt.Println(x1, y2, x2, y1)
	} else {
		fmt.Println(-1)
	}
}

