package main

import (
	"fmt"
	"strconv"
)

func main() {
	var a, b int
	fmt.Scanln(&a, &b)

	c := 0

	for i := 0; i < 2; i++ {
		if a >= b {
			c += a
			a--
		} else {
			c += b
			b--
		}
	}

	fmt.Println(c)
}

