package main

import "fmt"

func main() {
	var a, c, k, b int
	for {
		fmt.Scanf("%d", &a)
		if a < 3 {
			fmt.Println("0")
		} else {
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
}

