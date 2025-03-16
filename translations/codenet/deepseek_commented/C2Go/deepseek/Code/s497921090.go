package main

import (
	"fmt"
)

func main() {
	var n, a, b uint64 = 0, 0, 0
	fmt.Scan(&n)
	b = (n * (n - 1)) / 2
	fmt.Println(b)
}

