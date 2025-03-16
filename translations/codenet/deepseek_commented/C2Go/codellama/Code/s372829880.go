package main

import "fmt"

func main() {
	var x, a int
	fmt.Scanf("%d %d", &x, &a)
	fmt.Printf("%d\n", (x >= a) * 10)
}

