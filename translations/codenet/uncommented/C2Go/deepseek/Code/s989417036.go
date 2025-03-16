package main

import (
	"fmt"
)

func main() {
	var a, b, c int
	fmt.Scan(&a, &b, &c)
	if b <= c {
		fmt.Println("NO")
		return
	} else {
		d := a
		for i := 0; i < b; i++ {
			if d%b == c {
				fmt.Println("YES")
				return
			}
			d += a
		}
	}
	fmt.Println("NO")
}

