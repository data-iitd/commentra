package main

import (
	"fmt"
)

func main() {
	var B byte
	var OUT byte

	fmt.Scanf("%c", &B)

	switch B {
	case 'A':
		OUT = 'T'
	case 'T':
		OUT = 'A'
	case 'C':
		OUT = 'G'
	default:
		OUT = B
	}

	fmt.Printf("%c\n", OUT)
}

