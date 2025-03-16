package main

import (
	"fmt"
)

func main() {
	var a, b, c, d int
	fmt.Scan(&a, &b, &c, &d)
	if a*b%2 == 1 && (c+d)%2 == 1 {
		fmt.Println("No")
	} else {
		fmt.Println("Yes")
	}
}

