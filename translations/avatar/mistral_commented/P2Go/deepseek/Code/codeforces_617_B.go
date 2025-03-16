package main

import (
	"fmt"
	"math"
	"strings"
)

func main() {
	var a string
	fmt.Scan(&a)

	if !strings.Contains(a, "1") {
		fmt.Println(0)
		return
	}

	segments := strings.Split(strings.Trim(a, "0 "), "1")
	productOfZeros := 1
	for _, segment := range segments {
		productOfZeros *= (len(segment) + 1)
	}

	fmt.Println(productOfZeros)
}

