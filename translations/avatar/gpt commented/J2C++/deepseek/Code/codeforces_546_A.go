package main

import (
	"fmt"
)

func main() {
	var pandu, vundu, urdu int64
	var c int64 = 0

	fmt.Scan(&pandu, &vundu, &urdu)

	for i := int64(1); i <= urdu; i++ {
		c += i * pandu
	}

	if c < vundu {
		fmt.Print("0")
	} else {
		fmt.Print(c - vundu)
	}
}

