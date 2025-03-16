package main

import (
	"fmt"
	"math"
)

func main() {
	var a, b, c, d, e, k int
	fmt.Scan(&a, &b, &c, &d, &e, &k)

	fmt.Println(e-a <= k, ":(")
}

