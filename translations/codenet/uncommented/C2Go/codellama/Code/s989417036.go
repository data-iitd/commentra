package main

import "fmt"

func main() {
	var a, b, c, d, e, i int
	fmt.Scanf("%d%d%d", &a, &b, &c)
	if b <= c {
		fmt.Println("NO")
		return
	} else {
		d = a
		e = d % b
		for i = 0; i < b; i++ {
			d = d % b
			if d == c {
				fmt.Println("YES")
				return
			} else if i != 0 && d == c {
				fmt.Println("NO")
				return
			}
			d += a
		}
	}
	fmt.Println("NO")
}

