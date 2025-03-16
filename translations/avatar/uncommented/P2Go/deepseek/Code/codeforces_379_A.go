package main

import (
	"fmt"
)

func main() {
	var a, b int
	fmt.Scan(&a, &b)
	s := 0
	restoSciolte := 0
	for a > 0 || restoSciolte >= b {
		a += restoSciolte / b
		restoSciolte %= b
		s += a
		restoSciolte += a % b
		a /= b
	}
	fmt.Println(s)
}

