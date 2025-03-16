
package main

import "fmt"

func you(x, y int) int {
	var z int
	for {
		z = x % y
		x = y
		y = z
		if y <= 0 {
			break
		}
	}
	return x
}

func main() {
	var x, y, z int
	fmt.Scan(&x, &y)
	if x >= y {
		z = you(x, y)
	} else {
		z = you(y, x)
	}
	fmt.Println(z)
}

// 