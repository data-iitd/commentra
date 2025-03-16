package main

import (
	"fmt"
)

func main() {
	var H, W int
	fmt.Scanf("%d %d", &H, &W)
	m := H * W
	if m%2 == 0 {
		fmt.Println(m / 2)
	} else {
		fmt.Println(m/2 + 1)
	}
}

