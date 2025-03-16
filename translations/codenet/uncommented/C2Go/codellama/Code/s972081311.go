package main

import "fmt"

func main() {
	var n, sum int
	fmt.Scanf("%d", &n)
	sum = (n * (n + 1)) / 2
	fmt.Printf("%d\n", sum)
}

