package main

import (
	"fmt"
)

func main() {
	var a, b, x, w int
	for {
		_, err := fmt.Scan(&a, &b)
		if err != nil {
			break
		}
		x = a + b
		w = 0
		for x > 0 {
			w++
			x /= 10
		}
		fmt.Println(w)
	}
}

