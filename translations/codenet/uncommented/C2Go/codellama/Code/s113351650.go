package main

import "fmt"

func main() {
	var x int
	fmt.Scanf("%d", &x)
	if x == 0 {
		fmt.Println("1")
	}
	if x == 1 {
		fmt.Println("0")
	}
}

