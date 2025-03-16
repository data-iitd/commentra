package main

import (
	"fmt"
)

func binPrint(x, bits int) {
	for i := bits - 1; i >= 0; i-- {
		fmt.Printf("%d", x&(1<<i))
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

