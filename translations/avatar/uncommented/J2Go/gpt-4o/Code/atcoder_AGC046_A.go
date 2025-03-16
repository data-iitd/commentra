package main

import (
	"fmt"
)

func main() {
	var x int
	fmt.Scan(&x)
	count := 0
	tmp := x
	x = 0

	for x != 360 {
		x += tmp
		if x > 360 {
			x -= 360
		}
		count++
	}

	fmt.Println(count)
}

// <END-OF-CODE>
