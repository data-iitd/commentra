package main

import "fmt"

func main() {
	var r, D, x int
	fmt.Scan(&r, &D, &x)
	for i := 2; i <= 12; i++ {
		fmt.Println(int((r**(i-1))*(x+D/(1-r)) - D/(1-r)))
	}
}

