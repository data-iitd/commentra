package main

import (
	"fmt"
)

func main() {
	var a, b, c, x, y int
	fmt.Scan(&a, &b, &c, &x, &y)
	c *= 2
	if a+b <= c {
		fmt.Println(a*x + b*y)
	} else {
		if x <= y {
			if b <= c {
				fmt.Println(c*x + (y-x)*b)
			} else {
				fmt.Println(c * y)
			}
		} else {
			if a <= c {
				fmt.Println(c*y + (x-y)*a)
			} else {
				fmt.Println(c * x)
			}
		}
	}
}
