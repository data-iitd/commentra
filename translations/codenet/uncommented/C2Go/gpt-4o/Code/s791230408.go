package main

import (
	"fmt"
)

func main() {
	var a, b, c, j int

	fmt.Scan(&j)

	for i := 0; i < j; i++ {
		fmt.Scan(&a)
		fmt.Scan(&b)
		fmt.Scan(&c)

		max := a
		k := 0
		if max <= b {
			max = b
			k = 1
		}
		if max <= c {
			max = c
			k = 2
		}

		max = max * max
		a = a * a
		b = b * b
		c = c * c

		if k == 0 && max == b+c {
			fmt.Println("YES")
		} else if k == 1 && max == a+c {
			fmt.Println("YES")
		} else if k == 2 && max == a+b {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	}
}

// <END-OF-CODE>
