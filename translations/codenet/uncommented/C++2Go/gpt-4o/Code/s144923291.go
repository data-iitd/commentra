package main

import (
	"fmt"
)

func main() {
	var h, w int
	fmt.Scan(&h, &w)
	var t string
	s := "snuke"

	for i := 0; i < h; i++ {
		for j := 0; j < w; j++ {
			fmt.Scan(&t)
			if t == s {
				c := 'A' + rune(j)
				fmt.Printf("%c%d\n", c, i+1)
				return
			}
		}
	}
}

// <END-OF-CODE>
