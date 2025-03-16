package main

import (
	"fmt"
	"strings"
)

func main() {
	var a string
	fmt.Scan(&a)

	if strings.Count(a, "1") == 0 {
		fmt.Println(0)
	} else {
		parts := strings.Split(strings.Trim(a, "0 "), "1")
		product := 1
		for _, part := range parts {
			product *= (strings.Count(part, "0") + 1)
		}
		fmt.Println(product)
	}
}

