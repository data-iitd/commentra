package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)
	fmt.Println(n)

	m := n
	for i := n - 1; i > 0; i-- {
		if m%i == 0 {
			fmt.Println(i)
			m = i
		}
	}
}

// <END-OF-CODE>
