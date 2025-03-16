package main

import "fmt"

func main() {
	var a, c, k, b int
	for {
		_, _ = fmt.Scanf("%d", &a)
		if a < 3 {
			fmt.Println(0)
			continue
		}
		c, k = 0, 0
		b = a
		for a > 0 {
			b--
			c++
			if c == 3 {
				k++
				c = 0
			}
			a--
		}
		fmt.Println(k)
	}
}

