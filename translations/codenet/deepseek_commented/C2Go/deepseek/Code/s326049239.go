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

		if a < 3 {
			fmt.Println("0")
			continue
		}

		b = a
		c = 0
		k = 0

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

