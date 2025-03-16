package main

import (
	"fmt"
	"os"
)

func main() {
	var n int
	fmt.Fscan(os.Stdin, &n)
	w := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(os.Stdin, &w[i])
	}

	c := 2
	for _, i := range w {
		if i == 1 {
			fmt.Println(c)
		} else if i%2 == 0 {
			c = 3 - c
			fmt.Println(c)
		} else {
			fmt.Println(c)
		}
	}
}

// <END-OF-CODE>
