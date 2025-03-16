package main

import (
	"fmt"
	"strconv"
)

func main() {
	var a, b, c int
	fmt.Scanln(&a, &b)
	c = a - b*2
	if c < 0 {
		c = 0
	}
	fmt.Println(c)
}

