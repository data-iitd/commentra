package main

import (
	"fmt"
)

func main() {
	var a, b, mawari, menseki int

	fmt.Scanf("%d %d", &a, &b)
	mawari = a + a + b + b
	menseki = a * b
	fmt.Printf("%d %d\n", menseki, mawari)
}

// <END-OF-CODE>
