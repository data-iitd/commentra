package main

import (
	"fmt"
	"math"
)

func main() {
	var x int
	fmt.Scan(&x)

	ans := x + x*x + x*x*x

	fmt.Println(ans)
}

