package main

import (
	"fmt"
	"strings"
)

func main() {
	var h, w int
	fmt.Scan(&h, &w)
	var t string
	var s = "snuke"
	for i := 0; i < h; i++ {
		for j := 0; j < w; j++ {
			fmt.Scan(&t)
			if strings.Compare(s, t) == 0 {
				c := 'A' + j
				fmt.Printf("%c%d\n", c, i+1)
				return
			}
		}
	}
}

