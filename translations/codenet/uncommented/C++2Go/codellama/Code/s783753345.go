package main

import (
	"fmt"
)

func main() {
	var a, b int
	var S string
	for {
		fmt.Scan(&a, &S, &b)
		if S == "+" {
			fmt.Println(a + b)
		}
		if S == "-" {
			fmt.Println(a - b)
		}
		if S == "*" {
			fmt.Println(a * b)
		}
		if S == "/" {
			fmt.Println(a / b)
		}
		if S == "?" {
			break
		}
	}
}

