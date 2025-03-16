package main

import (
	"fmt"
)

func main() {
	var a, c, k, b int

	for {
		_, err := fmt.Scan(&a)
		if err != nil {
			break
		}

		c = 0
		k = 0

		if a < 3 {
			fmt.Println("0")
		} else {
			b = a

			for a > 0 {
				a--
				b--
				c++

				if c == 3 {
					k++
					c = 0
				}
			}
			fmt.Println(k)
		}
	}
}

