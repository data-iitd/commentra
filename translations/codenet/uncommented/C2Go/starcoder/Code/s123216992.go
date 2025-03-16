package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	for {
		a, b := read()
		if a == 0 && b == 0 {
			break
		}
		if b < a {
			a, b = b, a
		}
		fmt.Printf("%d %d\n", a, b)
	}
}

func read() (int, int) {
	a, b := 0, 0
	fmt.Scanf("%d %d", &a, &b)
	return a, b
}

