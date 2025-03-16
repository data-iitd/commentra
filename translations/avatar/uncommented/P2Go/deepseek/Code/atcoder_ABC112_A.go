package main

import (
	"fmt"
)

func main() {
	var age int
	fmt.Scan(&age)
	if age == 1 {
		fmt.Println("Hello World")
	} else {
		var a, b int
		fmt.Scan(&a, &b)
		fmt.Println(a + b)
	}
}

