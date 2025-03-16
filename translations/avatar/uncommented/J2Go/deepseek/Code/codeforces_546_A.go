package main

import (
	"fmt"
)

func main() {
	var pandu, vundu, urdu, c int64
	fmt.Scan(&pandu, &vundu, &urdu)
	for i := 1; i <= int(urdu); i++ {
		c += i * int(pandu)
	}
	if c < vundu {
		fmt.Print("0")
	} else {
		fmt.Print(c - vundu)
	}
}

