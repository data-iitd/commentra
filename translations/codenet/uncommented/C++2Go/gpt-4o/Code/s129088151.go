package main

import (
	"fmt"
)

func main() {
	var n int
	var str string
	var com string
	T := make(map[string]bool)

	fmt.Scan(&n)
	for i := 0; i < n; i++ {
		fmt.Scan(&com, &str)
		if com[0] == 'i' {
			T[str] = true
		} else {
			if T[str] {
				fmt.Println("yes")
			} else {
				fmt.Println("no")
			}
		}
	}
}

// <END-OF-CODE>
