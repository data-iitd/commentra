
package main

import (
	"fmt"
	"strconv"
)

func main() {
	var t int
	fmt.Scan(&t)
	for i := 0; i < t; i++ {
		var a, b, c int
		fmt.Scan(&a, &b, &c)
		k := a / b
		if k*c >= a {
			fmt.Println("Yes")
		} else {
			fmt.Println("No")
		}
	}
}

// 