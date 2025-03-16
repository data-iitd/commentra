package main

import (
	"fmt"
)

func main() {
	for {
		var a, b int
		var S string
		fmt.Scan(&a, &S, &b)
		switch S {
		case "+":
			fmt.Println(a + b)
		case "-":
			fmt.Println(a - b)
		case "*":
			fmt.Println(a * b)
		case "/":
			fmt.Println(a / b)
		case "?":
			break
		}
	}
}

