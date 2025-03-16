package main

import "fmt"

func main() {
	var n, a, b, i, j uint64
	fmt.Scanf("%d", &n)
	b = (n * (n - 1)) / 2
	fmt.Printf("%d\n", b)
}

