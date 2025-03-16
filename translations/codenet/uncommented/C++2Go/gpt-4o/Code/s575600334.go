package main

import (
	"fmt"
)

func binPrint(x uint32, bits int) {
	for i := bits - 1; i >= 0; i-- {
		if (x & (1 << i)) != 0 {
			fmt.Print("1")
		} else {
			fmt.Print("0")
		}
	}
	fmt.Println()
}

func main() {
	var a, b uint32
	fmt.Scan(&a, &b)

	binPrint(a&b, 32)
	binPrint(a|b, 32)
	binPrint(a^b, 32)
}

// <END-OF-CODE>
