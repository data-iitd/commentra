package main

import (
	"fmt"
)

func main() {
	var A, B int
	fmt.Scan(&A, &B)

	amari := 0
	result := 0
	result = (B - 1) / (A - 1)
	amari = (B - 1) % (A - 1)

	if amari != 0 {
		result += 1
	}

	fmt.Println(result)
}
