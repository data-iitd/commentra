package main

import (
	"fmt"
)

func main() {
	var K, X int
	fmt.Scanf("%d %d", &K, &X)
	for i := X - K + 1; i <= X + K - 1; i++ {
		fmt.Print(i)
		if i < X+K-1 {
			fmt.Print(" ")
		}
	}
	fmt.Println()
}

// <END-OF-CODE>
