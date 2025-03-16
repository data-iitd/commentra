package main

import "fmt"

func main() {
	var a, b int
	fmt.Scan(&a, &b)
	mawari := 2 * (a + b)
	menseki := a * b
	fmt.Println(menseki, mawari)
}

