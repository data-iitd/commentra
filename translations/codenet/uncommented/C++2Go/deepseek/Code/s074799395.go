package main

import (
	"fmt"
)

func main() {
	var B, OUT byte
	fmt.Scan(&B)
	switch B {
	case 'A':
		OUT = 'T'
	case 'T':
		OUT = 'A'
	case 'C':
		OUT = 'G'
	default:
		OUT = 'C'
	}
	fmt.Println(string(OUT))
}

