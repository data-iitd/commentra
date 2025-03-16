package main

import (
	"fmt"
)

func binPrint(x int, bits int) {
	for i := bits - 1; i >= 0; i-- {
		fmt.Print(x & (1 << i) >> i)
	}
	fmt.Println()
}

func main() {
	var a, b int
	fmt.Scan(&a, &b)

	binPrint(a&b, 32)
	binPrint(a|b, 32)
	binPrint(a^b, 32)
}

