package main

import (
	"fmt"
)

func main() {
	var N int
	fmt.Scan(&N)
	idorder := make(map[int]int)

	for i := 1; i <= N; i++ {
		var A int
		fmt.Scan(&A)
		idorder[A] = i
	}

	for i := 1; i <= N; i++ {
		fmt.Print(idorder[i], " ")
	}
}

// <END-OF-CODE>
