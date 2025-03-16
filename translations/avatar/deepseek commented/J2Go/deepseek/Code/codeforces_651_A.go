package main

import (
	"fmt"
)

func main() {
	var a, b int
	fmt.Scan(&a, &b)
	c := 0

	if a == 1 && b == 1 {
		fmt.Println(0)
	} else {
		for a >= 1 || b >= 1 {
			if a >= b {
				b++
				a -= 2
			} else {
				a++
				b -= 2
			}
			if a <= 0 || b <= 0 {
				c++
				break
			}
			c++
		}
		fmt.Println(c)
	}
}
