package main

import "fmt"

func main() {
	var a, b, ar, le int

	fmt.Scan(&a, &b)

	ar = a * b

	le = 2 * (a + b)

	fmt.Println(ar, le)
}

