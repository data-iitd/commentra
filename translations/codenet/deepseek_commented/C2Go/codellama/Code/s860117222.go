package main

import "fmt"

func main() {
	var a, b, c int64
	fmt.Scanf("%d %d %d", &a, &b, &c)

	d := c - a - b
	if d > 0 && (4*a*b) < (d*d) {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

