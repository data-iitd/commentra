package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	for {
		var a, b int
		var S string
		fmt.Scan(&a, &S, &b)
		if S == "+" {
			fmt.Println(a + b)
		} else if S == "-" {
			fmt.Println(a - b)
		} else if S == "*" {
			fmt.Println(a * b)
		} else if S == "/" {
			fmt.Println(a / b)
		} else if S == "?" {
			break
		}
	}
}

