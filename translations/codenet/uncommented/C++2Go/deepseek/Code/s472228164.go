package main

import (
	"fmt"
)

func check(x, y int) string {
	if y%2 == 0 {
		t := (0.5 * float64(y)) - float64(x)
		if t >= 0 && float64(x)-t >= 0 {
			return "Yes"
		}
	}
	return "No"
}

func main() {
	var x, y int
	fmt.Scan(&x, &y)

	fmt.Println(check(x, y))
}

