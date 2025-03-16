package main

import (
	"fmt"
)

func main() {
	var a, b, c, count int
	fmt.Scan(&a, &b, &c)
	count = 0
	for i := a; i <= b; i++ {
		if c%i == 0 {
			count++
		}
	}
	fmt.Println(count)
}

// <END-OF-CODE>
