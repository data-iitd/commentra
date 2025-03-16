package main

import (
	"fmt"
)

func main() {
	var a, b int
	fmt.Scan(&a, &b)

	c := 0
	if a == 1 && b == 1 {
		fmt.Println(0)
	} else {
		for a >= 1 || b >= 1 {
			if a >= b {
				b++
				a -= 2
			} else {
				a++
				b -= 2
			}
			if a <= 0 || b <= 0 {
				c++
				break
			}
			c++
		}
		fmt.Println(c)
	}
}

// swap function is not needed in Go as we don't need to swap values like in Java
// debug function is also not needed in Go for this translation

// <END-OF-CODE>
