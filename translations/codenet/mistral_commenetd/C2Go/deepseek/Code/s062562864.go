package main

import (
	"fmt"
)

func main() {
	var a, b, c, d, i, j int
	fmt.Scan(&a, &b, &c, &d)
	i = a * b
	j = c * d
	if i > j {
		fmt.Println(i)
	} else {
		fmt.Println(j)
	}
}
