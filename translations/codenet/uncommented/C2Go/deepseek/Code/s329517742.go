package main

import "fmt"

func main() {
	var a, b int
	fmt.Scan(&a, &b)
	if 500*a >= b {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

