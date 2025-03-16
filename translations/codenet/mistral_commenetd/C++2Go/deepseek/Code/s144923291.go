package main

import (
	"fmt"
	"strings"
)

func main() {
	var h, w int
	fmt.Scan(&h, &w)

	var t [10]string
	var s = "snuke"

	for i := 0; i < h; i++ {
		for j := 0; j < w; j++ {
			fmt.Scan(&t[j])
			if strings.EqualFold(t[j], s) {
				c := 'A' + rune(j)
				fmt.Printf("%c%d\n", c, i+1)
				return
			}
		}
	}
}

